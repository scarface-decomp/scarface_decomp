// The script of function.html, kept in its own file so the site's Content-Security-Policy can refuse inline scripts.
(function () {
  'use strict';
  var REPO = 'scarface-decomp/scarface_decomp', BRANCH = 'main';
  var RAW = 'https://raw.githubusercontent.com/' + REPO + '/' + BRANCH + '/reports/';
  var SOURCES = ['data/', RAW];
  // ps2pause, ps2exotics, ...: the PS2 program's code overlays (portal/tools/ps2_overlay.py)
  var BIN = { xb: 'Xbox', pc: 'PC 1.00.2', proto: 'Xbox prototype (April 2006)', ps2: 'PS2',
              ps2pause: 'PS2 pause menu', ps2exotics: 'PS2 exotics shop', ps2modals: 'PS2 business screens',
              ps2modals1: 'PS2 empire and mansion screens', ps2modals2: 'PS2 weapon screens',
              ps2games: 'PS2 gambling mini-games' };
  var FILE = { xb: 'default.xbe', pc: 'Scarface.exe', proto: 'game.xbe', ps2: 'SLUS_211.11',
               ps2pause: 'PauseMenuOverlayf.bin', ps2exotics: 'ExoticsOverlayf.bin', ps2modals: 'ModalsOverlayf.bin',
               ps2modals1: 'ModalsOverlay1f.bin', ps2modals2: 'ModalsOverlay2f.bin', ps2games: 'MiniGamesOverlayf.bin' };
  var $ = function (id) { return document.getElementById(id); };
  var fmt = function (n) { return Number(n || 0).toLocaleString('en-US'); };
  function el(tag, text, cls) {
    var e = document.createElement(tag);
    if (text !== undefined) e.textContent = text;
    if (cls) e.className = cls;
    return e;
  }
  function getJson(name) {
    var i = 0;
    function next() {
      if (i >= SOURCES.length) return Promise.reject(new Error(name + ' not found'));
      var url = SOURCES[i++] + name;
      return fetch(url, { cache: 'no-cache' }).then(function (r) {
        if (!r.ok) throw new Error('HTTP ' + r.status);
        return r.text();
      }).then(function (t) { return JSON.parse(t); }).catch(next);
    }
    return next();
  }
  function pageUrl(key) { return 'function.html?f=' + encodeURIComponent(key); }

  // ------------------------------------------------------------------ the C++, coloured
  var KEYWORDS = ('alignas alignof asm auto break case catch class const const_cast constexpr continue default delete do ' +
    'dynamic_cast else enum explicit export extern false for friend goto if inline mutable namespace new noexcept nullptr ' +
    'operator private protected public register reinterpret_cast return sizeof static static_cast struct switch template this ' +
    'throw true try typedef typeid typename union using virtual volatile while __cdecl __stdcall __fastcall __thiscall').split(' ');
  var TYPES = ('void bool char short int long float double signed unsigned wchar_t size_t int8_t int16_t int32_t int64_t ' +
    'uint8_t uint16_t uint32_t uint64_t BYTE WORD DWORD BOOL').split(' ');
  var KW = {}, TY = {};
  KEYWORDS.forEach(function (k) { KW[k] = 1; });
  TYPES.forEach(function (k) { TY[k] = 1; });
  var TOKEN = /(\/\/[^\n]*|\/\*[\s\S]*?\*\/)|("(?:\\.|[^"\\\n])*"|'(?:\\.|[^'\\\n])*')|(^[ \t]*#[^\n]*)|(\b0x[0-9A-Fa-f]+[uUlL]*\b|\b\d+(?:\.\d+)?[fFuUlL]*\b)|([A-Za-z_]\w*)/gm;
  var ADDRESS_NAME = /^(?:sub|func|FUN|DAT|D|PTR|LAB|thunk)_[0-9A-Fa-f]{6,8}$/;

  // Split the code into lines of coloured pieces (all text, never HTML); names that are other functions or
  // data are collected, and linked when they are rebuilt too.
  function colour(code, linkFor) {
    var lines = [[]], used = {};
    function push(text, cls, href, title) {
      var parts = text.split('\n');
      parts.forEach(function (p, i) {
        if (i) lines.push([]);
        if (p) lines[lines.length - 1].push({ t: p, c: cls, href: href, title: title });
      });
    }
    var last = 0, m;
    TOKEN.lastIndex = 0;
    while ((m = TOKEN.exec(code))) {
      if (m.index > last) push(code.slice(last, m.index));
      var t = m[0];
      if (m[1]) push(t, 'tk-com');
      else if (m[2]) push(t, 'tk-str');
      else if (m[3]) push(t, 'tk-pre');
      else if (m[4]) push(t, 'tk-num');
      else if (KW[t]) push(t, 'tk-kw');
      else if (TY[t]) push(t, 'tk-type');
      else {
        var ref = linkFor(t);
        if (ref) { used[t] = ref; push(t, 'tk-ref', ref.href, ref.title); }
        else push(t);
      }
      last = TOKEN.lastIndex;
    }
    if (last < code.length) push(code.slice(last));
    return { lines: lines, used: used };
  }

  // ------------------------------------------------------------------ tidied for reading
  // Only the spacing changes: a line break after each statement and around each block, and indents by
  // depth. Strings, comments and everything else stay as they are, and the result is checked to have the
  // very same pieces in the same order (spacing never changes what C++ compiles to). Code that is laid out
  // already is left alone.
  var PIECE = /(\s*)(\/\/[^\n]*|\/\*[\s\S]*?\*\/|"(?:\\.|[^"\\\n])*"|'(?:\\.|[^'\\\n])*'|[A-Za-z0-9_$.]+|\S)/g;
  function pieces(code) {
    var out = [], m, line = true;
    PIECE.lastIndex = 0;
    while ((m = PIECE.exec(code))) {
      var ws = m[1], t = m[2];
      if (t === '#' && (line || /\n/.test(ws) || !out.length)) {          // a preprocessor line, whole
        var end = code.indexOf('\n', PIECE.lastIndex);
        end = end < 0 ? code.length : end;
        t += code.slice(PIECE.lastIndex, end);
        PIECE.lastIndex = end;
      }
      out.push({ ws: ws, t: t });
      line = false;
    }
    return out;
  }
  function needsTidy(code) {
    return code.split('\n').some(function (l) { return l.length > 100 || /\{[^}\n]*;[^\n]*\}/.test(l); });
  }
  function tidy(code) {
    var ps = pieces(code), out = '', depth = 0, paren = 0, braces = [], br = 0, prev = '';
    ps.forEach(function (p, i) {
      var t = p.t, sep, closed = false;
      var blank = (p.ws.match(/\n/g) || []).length > 1;
      if (!i) sep = '';
      else if (br) sep = br > 1 || blank ? '\n\n' : '\n';
      else sep = /\n/.test(p.ws) ? (blank ? '\n\n' : '\n') : (p.ws ? ' ' : '');
      if (t === '}') {
        closed = braces.pop();
        if (closed) { depth = Math.max(0, depth - 1); if (!/\n/.test(sep)) sep = '\n'; }
      }
      if (prev === '}' && /^(else|while|;|,|\))$/.test(t)) sep = p.ws ? ' ' : '';
      if (i && prev !== '{' && /^\/[\/*]/.test(t) && !/\n/.test(p.ws)) sep = ' ';   // a comment stays on its line
      if (/\n/.test(sep)) sep += new Array(depth + 1).join('    ');
      out += sep + t;
      br = 0;
      if (t === '(' || t === '[') paren++;
      else if (t === ')' || t === ']') paren = Math.max(0, paren - 1);
      else if (t === '{') {
        var inline = paren > 0 || /^(=|,|\(|return|\{)$/.test(prev);
        braces.push(!inline);
        if (!inline) { depth++; br = 1; }
      } else if (t === '}') {
        if (closed) br = depth === 0 ? 2 : 1;               // a blank line after a whole function
      } else if (t === ';' && paren === 0) br = 1;
      if (t.slice(0, 2) === '//' || t.charAt(0) === '#') br = Math.max(br, 1);   // these end at the line's end
      prev = t;
    });
    // the check: the same pieces, in the same order
    var a = ps.map(function (p) { return p.t; }), b = pieces(out).map(function (p) { return p.t; });
    if (a.length !== b.length || a.some(function (t, i) { return t !== b[i]; })) return null;
    return out;
  }

  function render(reg, key, names) {
    var entries = reg.entries || {};
    var e = entries[key];
    if (!e) { $('loading').hidden = true; $('missing').hidden = false; return; }

    // what every rebuilt function is called, per version, to link names in the code
    var bySymbol = {}, byAddr = {};
    Object.keys(entries).forEach(function (k) {
      var x = entries[k];
      if (x.bin === e.bin) byAddr[String(x.va).replace(/^.*\s/, '').replace(/^0X/i, '0x').toUpperCase().replace(/^0X/, '0x')] = k;
      if (x.bin === e.bin) bySymbol[x.symbol] = k;
      var short = x.symbol.replace(/^.*::/, '');
      if (x.bin === e.bin && /^(sub|func)_/.test(short)) bySymbol[short] = k;
    });
    function linkFor(word) {
      if (word === e.symbol) return null;
      var hit = bySymbol[word];
      if (hit && hit !== key) return { href: pageUrl(hit), title: 'Rebuilt: ' + entries[hit].symbol, key: hit };
      if (ADDRESS_NAME.test(word)) {
        var addr = '0x' + ('00000000' + word.replace(/^[A-Za-z]+_/, '').toUpperCase()).slice(-8);
        if (addr === String(e.va).toUpperCase().replace(/^0X/, '0x').replace(/^.*\s/, '')) return null;   // itself
        var at = byAddr[addr];
        if (at && at !== key) return { href: pageUrl(at), title: 'Rebuilt: ' + entries[at].symbol, key: at };
        var known = names[e.bin + ':' + addr];
        return { title: known ? 'Probably ' + known.name + ' (not rebuilt yet)' : 'Not rebuilt yet', known: known, addr: addr };
      }
      return null;
    }

    // name: class and function
    var sym = e.symbol || '';
    var cut = sym.lastIndexOf('::');
    $('cls').textContent = cut > 0 ? sym.slice(0, cut) + '::' : '';
    $('name').textContent = cut > 0 ? sym.slice(cut + 2) : sym;
    document.title = sym + ' (' + (BIN[e.bin] || e.bin) + ') | Scarface decomp';
    $('crumb-ver').textContent = BIN[e.bin] || e.bin;
    var canon = document.createElement('link');
    canon.rel = 'canonical';
    canon.href = 'https://scarface-decomp.pages.dev/' + pageUrl(key);
    document.head.appendChild(canon);

    if (e.what) {
      $('what').hidden = false;
      $('what').textContent = e.what;
      var by = e.what_by || e.verified_by;
      if (by) $('what').appendChild(el('small', 'In plain English, by ' + by));
      var desc = document.querySelector('meta[name="description"]');
      if (desc) desc.setAttribute('content', e.what);
    }
    var facts = $('facts');
    function fact(label, value, href) {
      var d = el('div'), dt = el('dt', label), dd = el('dd');
      if (href) { var a = el('a', value); a.href = href; a.target = '_blank'; a.rel = 'noopener noreferrer'; dd.appendChild(a); }
      else dd.textContent = value;
      d.appendChild(dt); d.appendChild(dd); facts.appendChild(d);
    }
    fact('Version', (BIN[e.bin] || e.bin) + ' (' + (FILE[e.bin] || '') + ')');
    fact('Address', e.va);
    fact('Size', fmt(e.size) + (Number(e.size) === 1 ? ' byte' : ' bytes'));
    fact('Rebuilt by', e.verified_by || 'early bulk work');
    if (e.verified_at) fact('Verified', String(e.verified_at).slice(0, 10));
    if (e.revised_by) fact('Cleaned up by', e.revised_by);
    if (e.tool_used) fact('Helped by', e.tool_used);
    fact('Compiler', (/^ps2/.test(e.bin) ? 'CodeWarrior for PS2 3.0.1' : 'Visual C++ ' + (e.compiler || '7.10')));
    fact('Flags', e.flags || '');
    var src = sourcePath(e);
    if (src) fact('In the repository', src, 'https://github.com/' + REPO + '/blob/' + BRANCH + '/' + src.split('/').map(encodeURIComponent).join('/'));
    if (e.note) { $('note').hidden = false; $('note-text').textContent = ' ' + e.note; }

    // the code: tidied for reading when it is crammed together, or exactly as it was verified
    var exact = String(e.code || '').replace(/\r\n/g, '\n').replace(/\s+$/, '');
    var tidied = needsTidy(exact) ? tidy(exact) : null;
    var file = (sym.replace(/[^A-Za-z0-9_]+/g, '_').replace(/^_+|_+$/g, '') || 'function') + '_' + String(e.va).replace(/^.*\s|^0x/gi, '') + '.cpp';
    var shown = '', blobUrl = '';
    var c = colour(exact, linkFor);
    function draw(useTidy) {
      shown = useTidy && tidied ? tidied : exact;
      var lines = colour(shown, linkFor).lines, table = el('table');
      lines.forEach(function (line, i) {
        var tr = el('tr'), n = el('td', String(i + 1), 'n'), td = el('td');
        n.setAttribute('aria-hidden', 'true');
        line.forEach(function (p) {
          var node;
          if (p.href) { node = el('a', p.t, p.c); node.href = p.href; }
          else if (p.c) node = el('span', p.t, p.c);
          else node = document.createTextNode(p.t);
          if (p.title && node.setAttribute) node.setAttribute('title', p.title);
          td.appendChild(node);
        });
        tr.appendChild(n); tr.appendChild(td); table.appendChild(tr);
      });
      $('code').textContent = '';
      $('code').appendChild(table);
      $('view-tidy').setAttribute('aria-pressed', shown === tidied ? 'true' : 'false');
      $('view-exact').setAttribute('aria-pressed', shown === tidied ? 'false' : 'true');
      $('view-note').textContent = shown === tidied
        ? 'Tidied for reading: only the line breaks and indents differ from the text that was verified, so it compiles to the same bytes.'
        : 'Exactly the text that was compiled and verified.';
      if (blobUrl) URL.revokeObjectURL(blobUrl);
      blobUrl = URL.createObjectURL(new Blob([shown + '\n'], { type: 'text/plain' }));
      $('download').href = blobUrl;
      $('download').setAttribute('download', file);
    }
    $('view-tidy').parentNode.hidden = !tidied;
    $('view-tidy').addEventListener('click', function () { draw(true); });
    $('view-exact').addEventListener('click', function () { draw(false); });
    draw(true);
    $('copy').addEventListener('click', function () {
      var b = $('copy');
      if (navigator.clipboard) navigator.clipboard.writeText(shown + '\n').then(function () {
        b.textContent = 'Copied'; setTimeout(function () { b.textContent = 'Copy'; }, 1400);
      }, function () {});
    });

    // what it uses, and what uses it
    var uses = $('uses');
    Object.keys(c.used).sort().forEach(function (word) {
      var r = c.used[word], li = el('li'), cd = el('code');
      if (r.key) { var a = el('a', word); a.href = r.href; cd.appendChild(a); li.appendChild(cd); li.appendChild(el('span', 'rebuilt', 's')); }
      else {
        cd.textContent = word; li.appendChild(cd); li.appendChild(el('span', 'not rebuilt yet', 's'));
        if (r.known) li.appendChild(el('span', 'Probably ' + r.known.name + (r.known.by ? ' (named by ' + r.known.by + ')' : ''), 'w'));
      }
      uses.appendChild(li);
    });
    if (!uses.children.length) uses.appendChild(el('li', 'Nothing else: it stands on its own.', 's'));
    var used = $('used');
    var own = [sym];
    var shortName = sym.replace(/^.*::/, '');
    if (/^(sub|func)_/.test(shortName)) own.push(shortName);
    Object.keys(entries).forEach(function (k) {
      var x = entries[k];
      if (k === key || x.bin !== e.bin) return;
      var text = String(x.code || '');
      if (own.some(function (n) { return n.length >= 8 && new RegExp('\\b' + n.replace(/[^\w]/g, '\\$&') + '\\b').test(text); })) {
        var li = el('li'), cd = el('code'), a = el('a', x.symbol);
        a.href = pageUrl(k); cd.appendChild(a); li.appendChild(cd); li.appendChild(el('span', x.va, 's'));
        used.appendChild(li);
      }
    });
    if (!used.children.length) used.appendChild(el('li', 'No rebuilt function refers to it yet.', 's'));

    // neighbours by address in the same version
    var same = Object.keys(entries).filter(function (k) { return entries[k].bin === e.bin; })
      .sort(function (a, b) { return parseInt(entries[a].va, 16) - parseInt(entries[b].va, 16); });
    var at = same.indexOf(key), pager = $('pager');
    [[at - 1, 'prev', '‹ Before it'], [at + 1, 'next', 'After it ›']].forEach(function (p) {
      if (p[0] < 0 || p[0] >= same.length) return;
      var k = same[p[0]], a = el('a', '', p[1]);
      a.href = pageUrl(k);
      a.appendChild(el('small', p[2] + ' in ' + (BIN[e.bin] || e.bin)));
      a.appendChild(el('code', entries[k].symbol));
      pager.appendChild(a);
    });

    $('loading').hidden = true;
    $('fn').hidden = false;
  }

  // the file it is in (the same as the main page's list)
  function sourcePath(e) {
    var files = { pc: 'Original_Binary_Order_PC_1002.cpp', xb: 'Original_Binary_Order_Xbox.cpp',
                  proto: 'Original_Binary_Order_Proto.cpp', ps2: 'Original_Binary_Order_PS2.cpp',
                  ps2pause: 'Original_Binary_Order_PS2_PauseMenu.cpp', ps2exotics: 'Original_Binary_Order_PS2_Exotics.cpp',
                  ps2modals: 'Original_Binary_Order_PS2_Modals.cpp', ps2modals1: 'Original_Binary_Order_PS2_Modals1.cpp',
                  ps2modals2: 'Original_Binary_Order_PS2_Modals2.cpp', ps2games: 'Original_Binary_Order_PS2_MiniGames.cpp' };
    if (!e.source || e.source === 'portal') return files[e.bin] ? 'reconstructed_src/' + files[e.bin] : '';
    return 'reconstructed_src/' + e.source;
  }

  var key = new URLSearchParams(location.search).get('f') || '';
  getJson('verified_registry.json').then(function (reg) {
    return getJson('names.json').then(function (n) { return [reg, (n && n.names) || {}]; }, function () { return [reg, {}]; });
  }).then(function (r) { render(r[0], key, r[1]); }, function () {
    $('loading').textContent = 'Couldn\'t load the list of rebuilt functions. Try again in a moment.';
  });
})();
