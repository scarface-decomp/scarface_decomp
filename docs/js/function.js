// The script of function.html, kept in its own file so the site's Content-Security-Policy can refuse inline scripts.
(function () {
  'use strict';
  var REPO = 'scarface-decomp/scarface_decomp', BRANCH = 'main';
  var RAW = 'https://raw.githubusercontent.com/' + REPO + '/' + BRANCH + '/';
  var SOURCES = ['data/', RAW + 'reports/'];
  // The list of rebuilt functions (portal/tools/registry_outputs.py): beside this page, or in the repository's docs/.
  // It has no code; each function links to its own lines on GitHub.
  var SITE = ['', RAW + 'docs/'];
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
  function getJson(name, sources) {
    var list = sources || SOURCES, i = 0;
    function next() {
      if (i >= list.length) return Promise.reject(new Error(name + ' not found'));
      var url = list[i++] + name;
      return fetch(url, { cache: 'no-cache' }).then(function (r) {
        if (!r.ok) throw new Error('HTTP ' + r.status);
        return r.text();
      }).then(function (t) { return JSON.parse(t); }).catch(next);
    }
    return next();
  }
  function pageUrl(key) { return 'function.html?f=' + encodeURIComponent(key); }

  // Names made from an address: another function or a global (the same pattern as registry_outputs.py).
  var ADDRESS_NAME = /^(?:sub|func|FUN|DAT|D|PTR|LAB|thunk)_[0-9A-Fa-f]{6,8}$/;

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

    // the code: on GitHub, at the lines of its block in its class's file
    var path = sourcePath(e);
    var url = 'https://github.com/' + REPO + '/blob/' + BRANCH + '/' + path.split('/').map(encodeURIComponent).join('/') +
      (e.lines && e.lines.length === 2 ? '#L' + e.lines[0] + '-L' + e.lines[1] : '');
    $('code-link').href = url;
    $('code-where').textContent = 'In ' + path + (e.lines ? ', lines ' + e.lines[0] + '\u2013' + e.lines[1] : '') + '.';

    // what it uses, and what uses it
    var uses = $('uses');
    (e.refs || []).forEach(function (word) {
      var r = linkFor(word), li = el('li'), cd = el('code');
      if (!r) return;
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
      var refs = x.refs || [];
      if (own.some(function (n) { return (n.length >= 8 || n.indexOf('::') > 0) && refs.indexOf(n) >= 0; })) {
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
    if (e.file) return e.file;
    var files = { pc: 'Original_Binary_Order_PC_1002.cpp', xb: 'Original_Binary_Order_Xbox.cpp',
                  proto: 'Original_Binary_Order_Proto.cpp', ps2: 'Original_Binary_Order_PS2.cpp',
                  ps2pause: 'Original_Binary_Order_PS2_PauseMenu.cpp', ps2exotics: 'Original_Binary_Order_PS2_Exotics.cpp',
                  ps2modals: 'Original_Binary_Order_PS2_Modals.cpp', ps2modals1: 'Original_Binary_Order_PS2_Modals1.cpp',
                  ps2modals2: 'Original_Binary_Order_PS2_Modals2.cpp', ps2games: 'Original_Binary_Order_PS2_MiniGames.cpp' };
    if (!e.source || e.source === 'portal') return files[e.bin] ? 'reconstructed_src/' + files[e.bin] : '';
    return 'reconstructed_src/' + e.source;
  }

  var key = new URLSearchParams(location.search).get('f') || '';
  getJson('functions.json', SITE).then(function (reg) {
    return getJson('names.json').then(function (n) { return [reg, (n && n.names) || {}]; }, function () { return [reg, {}]; });
  }).then(function (r) { render(r[0], key, r[1]); }, function () {
    $('loading').textContent = 'Couldn\'t load the list of rebuilt functions. Try again in a moment.';
  });
})();
