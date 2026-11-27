// The script of explore.html, kept in its own file so the site's Content-Security-Policy can refuse inline scripts.
// Reads map.json (portal/tools/registry_outputs.py): every function of each program, rebuilt or not, in address order.
(function () {
  'use strict';
  var REPO = 'scarface-decomp/scarface_decomp', BRANCH = 'main';
  var RAW = 'https://raw.githubusercontent.com/' + REPO + '/' + BRANCH + '/';
  var SITE = ['', RAW + 'docs/'];
  var ORDER = ['xb', 'pc', 'proto', 'ps2'];
  var TAB = { xb: 'Xbox', pc: 'PC 1.00.2', proto: 'Xbox prototype', ps2: 'PS2' };
  // the versions the portal's agent.py works on; the PS2 game is worked on through decomp.me
  var AGENT = { xb: true, pc: true, proto: true };
  var PAGE = 60;
  var C_OPEN = [46, 46, 46], C_DONE = [234, 68, 77], C_HL = [242, 239, 234], C_BG = [5, 5, 5];

  var $ = function (id) { return document.getElementById(id); };
  var fmt = function (n) { return Number(n || 0).toLocaleString('en-US'); };
  function el(tag, text, cls) {
    var e = document.createElement(tag);
    if (text !== undefined && text !== null) e.textContent = text;
    if (cls) e.className = cls;
    return e;
  }
  function hex(va) { return '0x' + ('00000000' + va.toString(16).toUpperCase()).slice(-8); }
  function getJson(name) {
    var i = 0;
    function next() {
      if (i >= SITE.length) return Promise.reject(new Error(name + ' not found'));
      var url = SITE[i++] + name;
      return fetch(url, { cache: 'no-cache' }).then(function (r) {
        if (!r.ok) throw new Error('HTTP ' + r.status);
        return r.json();
      }).catch(next);
    }
    return next();
  }

  // ---- one program's functions, unpacked ------------------------------------------------------------
  function unpack(key, raw) {
    var n = raw.s.length, va = new Array(n), size = new Int32Array(n), done = new Uint8Array(n);
    var cum = new Float64Array(n + 1), mcum = new Float64Array(n + 1);
    var at = raw.start;
    for (var i = 0; i < n; i++) {
      at += raw.d[i];
      va[i] = at;
      size[i] = Math.max(1, raw.s[i]);
      done[i] = raw.m.charCodeAt(i) === 49 ? 1 : 0;
      cum[i + 1] = cum[i] + size[i];
      mcum[i + 1] = mcum[i] + (done[i] ? size[i] : 0);
    }
    var nDone = 0;
    for (i = 0; i < n; i++) nDone += done[i];
    return { key: key, label: raw.label, n: n, va: va, size: size, done: done, cum: cum, mcum: mcum, nDone: nDone,
             names: raw.names || {}, better: raw.better || {}, what: raw.what || {}, text: null };
  }
  function nameOf(p, i) { return p.names[i] || ('sub_' + hex(p.va[i]).slice(2)); }
  function shownName(p, i) { return p.better[i] || nameOf(p, i); }
  function keyOf(p, i) { return p.key + ':' + hex(p.va[i]); }
  function searchText(p) {
    if (p.text) return p.text;
    var t = new Array(p.n);
    for (var i = 0; i < p.n; i++) {
      t[i] = (nameOf(p, i) + ' ' + (p.better[i] || '') + ' ' + hex(p.va[i]) + ' ' + (p.what[i] || '')).toLowerCase();
    }
    p.text = t;
    return t;
  }
  // which function holds byte `x` of the program's code laid end to end
  function atByte(p, x) {
    var lo = 0, hi = p.n - 1;
    while (lo < hi) {
      var mid = (lo + hi + 1) >> 1;
      if (p.cum[mid] <= x) lo = mid; else hi = mid - 1;
    }
    return lo;
  }

  // ---- state -----------------------------------------------------------------------------------------
  var data = null, progs = {}, cur = null, mode = 'size', hl = null, sel = -1, results = [], shown = 0, layout = null;

  // ---- the map ---------------------------------------------------------------------------------------
  var canvas = $('map'), tip = $('tip');

  function draw() {
    if (!cur) return;
    var p = cur, box = canvas.parentNode, cw = Math.max(200, box.clientWidth - 2);
    var dpr = Math.min(2, window.devicePixelRatio || 1), cell, cols, rows, ch;
    if (mode === 'size') {
      cell = 2;
      ch = window.matchMedia('(max-width: 640px)').matches ? 260 : 340;
      cols = Math.floor(cw / cell);
      rows = Math.floor(ch / cell);
    } else {
      cell = Math.max(2, Math.floor(Math.sqrt(cw * 300 / p.n)));
      cols = Math.floor(cw / cell);
      rows = Math.ceil(p.n / cols);
      ch = rows * cell;
    }
    canvas.style.height = ch + 'px';
    canvas.width = Math.round(cw * dpr);
    canvas.height = Math.round(ch * dpr);
    var W = canvas.width, H = canvas.height, ctx = canvas.getContext('2d');
    var img = ctx.createImageData(W, H), px = img.data;
    for (var q = 0; q < px.length; q += 4) { px[q] = C_BG[0]; px[q + 1] = C_BG[1]; px[q + 2] = C_BG[2]; px[q + 3] = 255; }
    var hcum = null;
    if (hl) {
      hcum = new Int32Array(p.n + 1);
      for (var h = 0; h < p.n; h++) hcum[h + 1] = hcum[h] + (hl[h] ? 1 : 0);
    }
    function fill(cx, cy, rgb, gap) {
      var x0 = Math.round(cx * cell * dpr), y0 = Math.round(cy * cell * dpr);
      var x1 = Math.round((cx + 1) * cell * dpr) - gap, y1 = Math.round((cy + 1) * cell * dpr) - gap;
      for (var y = y0; y < y1 && y < H; y++) {
        for (var x = x0; x < x1 && x < W; x++) {
          var o = (y * W + x) * 4;
          px[o] = rgb[0]; px[o + 1] = rgb[1]; px[o + 2] = rgb[2];
        }
      }
    }
    var total = p.cum[p.n], cells = cols * rows;
    if (mode === 'size') {
      // each cell: an equal share of the code's bytes, coloured by how much of it is rebuilt
      var per = total / cells, i = 0, c, rgb = [0, 0, 0];
      var M = function (x) {          // rebuilt bytes before byte x (x only grows, so i only moves forward)
        while (i < p.n - 1 && p.cum[i + 1] <= x) i++;
        return p.mcum[i] + (p.done[i] ? Math.min(x - p.cum[i], p.size[i]) : 0);
      };
      var a = 0, ma = 0;
      for (c = 0; c < cells; c++) {
        var b = Math.min(total, (c + 1) * per), i0 = i;
        var mb = M(b), f = b > a ? (mb - ma) / (b - a) : 0;
        var i1 = (i > i0 && p.cum[i] >= b) ? i - 1 : i;   // the last function with a byte in this cell
        if (hcum && hcum[Math.min(p.n, i1 + 1)] - hcum[i0] > 0) {
          rgb = C_HL;
        } else {
          rgb = [Math.round(C_OPEN[0] + (C_DONE[0] - C_OPEN[0]) * f), Math.round(C_OPEN[1] + (C_DONE[1] - C_OPEN[1]) * f),
                 Math.round(C_OPEN[2] + (C_DONE[2] - C_OPEN[2]) * f)];
        }
        fill(c % cols, Math.floor(c / cols), rgb, 0);
        a = b; ma = mb;
      }
    } else {
      var gap = cell >= 4 ? Math.round(dpr) : 0;
      for (var k = 0; k < p.n; k++) {
        fill(k % cols, Math.floor(k / cols), hl && hl[k] ? C_HL : (p.done[k] ? C_DONE : C_OPEN), gap);
      }
    }
    ctx.putImageData(img, 0, 0);
    layout = { cell: cell, cols: cols, rows: rows, cells: cells, per: total / cells, cw: cw, ch: ch };
    // a few search hits are single cells: ring each one so it can be found
    if (hl && results.length && results.length <= 200) {
      ctx.strokeStyle = 'rgba(242,239,234,0.85)';
      ctx.lineWidth = Math.max(1, Math.round(dpr));
      for (var r = 0; r < results.length; r++) {
        var at = mode === 'size' ? Math.min(cells - 1, Math.floor(p.cum[results[r]] / layout.per)) : results[r];
        var rx = (at % cols) * cell, ry = Math.floor(at / cols) * cell;
        ctx.strokeRect((rx - 3) * dpr, (ry - 3) * dpr, (cell + 6) * dpr, (cell + 6) * dpr);
      }
    }
    if (sel >= 0) markSelected(ctx, dpr);
  }

  // a white frame round the chosen function's place
  function markSelected(ctx, dpr) {
    var p = cur, L = layout, cs = [];
    if (mode === 'size') {
      var c0 = Math.floor(p.cum[sel] / L.per), c1 = Math.max(c0, Math.ceil(p.cum[sel + 1] / L.per) - 1);
      cs = [c0, Math.min(c1, L.cells - 1)];
    } else {
      cs = [sel, sel];
    }
    var x0 = cs[0] % L.cols, y0 = Math.floor(cs[0] / L.cols), y1 = Math.floor(cs[1] / L.cols);
    var x1 = y1 === y0 ? cs[1] % L.cols : L.cols - 1;
    var pad = 3;
    ctx.strokeStyle = '#F2EFEA';
    ctx.lineWidth = Math.max(1, Math.round(dpr * 1.5));
    ctx.strokeRect((x0 * L.cell - pad) * dpr, (y0 * L.cell - pad) * dpr,
                   ((x1 - x0 + 1) * L.cell + 2 * pad) * dpr, ((y1 - y0 + 1) * L.cell + 2 * pad) * dpr);
  }

  function fnAt(ev) {
    if (!layout || !cur) return -1;
    var r = canvas.getBoundingClientRect(), x = ev.clientX - r.left, y = ev.clientY - r.top;
    var cx = Math.floor(x / layout.cell), cy = Math.floor(y / layout.cell);
    if (cx < 0 || cy < 0 || cx >= layout.cols || cy >= layout.rows) return -1;
    var c = cy * layout.cols + cx;
    if (mode === 'size') return atByte(cur, Math.min(cur.cum[cur.n] - 1, (c + 0.5) * layout.per));
    return c < cur.n ? c : -1;
  }

  function describe(i, into, full) {
    var p = cur;
    into.textContent = '';
    into.appendChild(el('div', shownName(p, i), 'n'));
    if (p.better[i]) into.appendChild(el('div', 'placeholder in the code: ' + nameOf(p, i), 'g'));
    into.appendChild(el('div', hex(p.va[i]) + ' · ' + fmt(p.size[i]) + ' bytes · ' + (p.done[i] ? 'rebuilt' : 'still to do'), 'g'));
    if (p.what[i]) into.appendChild(el('div', p.what[i]));
    if (!full) return;
    var line = el('div');
    line.style.marginTop = '8px';
    if (p.done[i]) {
      var a = el('a', 'Open its page: who rebuilt it, its C++, what it uses');
      a.href = 'function.html?f=' + encodeURIComponent(keyOf(p, i));
      line.appendChild(a);
      into.appendChild(line);
    } else if (AGENT[p.key]) {
      line.appendChild(document.createTextNode('Still to do. With the project set up (main page, "Start helping"), this starts it:'));
      into.appendChild(line);
      into.appendChild(el('pre', 'python portal/agent.py packet ' + p.key + ' ' + hex(p.va[i])));
    } else {
      line.appendChild(document.createTextNode('Still to do. PS2 functions are worked on with the portal\'s decomp.me button: search for ' + hex(p.va[i]) + ' in the portal\'s PS2 list.'));
      into.appendChild(line);
    }
  }

  function select(i, scroll) {
    sel = i;
    var pick = $('pick');
    if (i < 0) { pick.hidden = true; draw(); return; }
    describe(i, pick, true);
    pick.hidden = false;
    draw();
    setUrl();
    if (scroll) $('mapbox').scrollIntoView({ behavior: 'smooth', block: 'center' });
  }

  canvas.addEventListener('mousemove', function (ev) {
    var i = fnAt(ev);
    if (i < 0) { tip.hidden = true; return; }
    describe(i, tip, false);
    tip.hidden = false;
    var box = $('mapbox').getBoundingClientRect(), x = ev.clientX - box.left + 14, y = ev.clientY - box.top + 14;
    var w = tip.offsetWidth, h = tip.offsetHeight;
    if (x + w > box.width) x = Math.max(0, ev.clientX - box.left - w - 14);
    if (y + h > box.height + 40) y = Math.max(0, ev.clientY - box.top - h - 14);
    tip.style.left = x + 'px';
    tip.style.top = y + 'px';
  });
  canvas.addEventListener('mouseleave', function () { tip.hidden = true; });
  canvas.addEventListener('click', function (ev) {
    var i = fnAt(ev);
    tip.hidden = true;
    if (i >= 0) select(i, false);
  });

  // ---- the search ------------------------------------------------------------------------------------
  function runSearch(keepSel) {
    var p = cur, q = $('q').value.trim().toLowerCase(), st = $('state').value, sort = $('sort').value;
    var words = q ? q.split(/\s+/) : [];
    // an address typed without 0x or leading zeros still finds the function
    var addr = /^(0x)?[0-9a-f]{4,8}$/.test(q) ? parseInt(q.replace(/^0x/, ''), 16) : -1;
    var text = words.length ? searchText(p) : null, out = [];
    for (var i = 0; i < p.n; i++) {
      if (st && String(p.done[i]) !== st) continue;
      if (words.length) {
        var ok = addr >= 0 && p.va[i] <= addr && addr < p.va[i] + p.size[i];
        if (!ok) {
          ok = true;
          for (var w = 0; w < words.length; w++) if (text[i].indexOf(words[w]) < 0) { ok = false; break; }
        }
        if (!ok) continue;
      }
      out.push(i);
    }
    if (sort === 'small') out.sort(function (a, b) { return p.size[a] - p.size[b] || a - b; });
    if (sort === 'big') out.sort(function (a, b) { return p.size[b] - p.size[a] || a - b; });
    results = out;
    hl = null;
    if (words.length || st) {
      hl = new Uint8Array(p.n);
      for (var k = 0; k < out.length; k++) hl[out[k]] = 1;
    }
    $('hl-key').hidden = !hl;
    shown = 0;
    $('rows').textContent = '';
    var bytes = 0;
    for (k = 0; k < out.length; k++) bytes += p.size[out[k]];
    $('count').textContent = out.length === p.n ? fmt(p.n) + ' functions'
      : fmt(out.length) + ' of ' + fmt(p.n) + ' functions (' + fmt(bytes) + ' bytes), shown in white on the map';
    if (!out.length) $('rows').appendChild(el('div', 'Nothing found. Try part of a name (car, tony, sound), an address, or fewer words.', 'empty'));
    more();
    if (!keepSel) sel = -1;
    draw();
    setUrl();
  }

  function row(i) {
    var p = cur, r = el('div', null, 'row'), name = el('div', null, 'p');
    if (p.done[i]) {
      var a = el('a', shownName(p, i));
      a.href = 'function.html?f=' + encodeURIComponent(keyOf(p, i));
      name.appendChild(a);
    } else {
      name.appendChild(document.createTextNode(shownName(p, i)));
    }
    var loc = el('button', 'show on map', 'loc');
    loc.type = 'button';
    loc.addEventListener('click', function () { select(i, true); });
    name.appendChild(loc);
    if (p.better[i]) name.appendChild(el('div', nameOf(p, i), 'also'));
    r.appendChild(name);
    r.appendChild(el('div', hex(p.va[i]), 'a'));
    r.appendChild(el('div', fmt(p.size[i]) + ' B', 'z'));
    r.appendChild(el('div', p.done[i] ? 'rebuilt' : 'to do', 'st ' + (p.done[i] ? 'done' : 'open')));
    if (p.what[i]) r.appendChild(el('div', p.what[i], 'd'));
    return r;
  }
  function more() {
    var box = $('rows'), end = Math.min(results.length, shown + PAGE);
    var frag = document.createDocumentFragment();
    for (var k = shown; k < end; k++) frag.appendChild(row(results[k]));
    box.appendChild(frag);
    shown = end;
    $('more').hidden = shown >= results.length;
    $('more').textContent = 'Show more (' + fmt(results.length - shown) + ' left)';
  }

  // a small open function to start on: under 64 bytes when there is one
  function randomOpen() {
    var p = cur, pool = [];
    for (var i = 0; i < p.n; i++) if (!p.done[i] && p.size[i] >= 4 && p.size[i] <= 64) pool.push(i);
    if (!pool.length) for (i = 0; i < p.n; i++) if (!p.done[i]) pool.push(i);
    if (!pool.length) return;
    select(pool[Math.floor(Math.random() * pool.length)], true);
  }

  // ---- tabs, stats, address ---------------------------------------------------------------------------
  function stats() {
    var p = cur, box = $('stats'), doneB = p.mcum[p.n], all = p.cum[p.n];
    box.textContent = '';
    function stat(big, small) {
      var s = el('div');
      s.appendChild(el('b', big));
      s.appendChild(el('span', small));
      box.appendChild(s);
    }
    stat((100 * p.nDone / p.n).toFixed(1) + '%', fmt(p.nDone) + ' of ' + fmt(p.n) + ' functions');
    stat((100 * doneB / all).toFixed(1) + '%', fmt(doneB) + ' of ' + fmt(all) + ' bytes of code');
    var s = el('div');
    s.appendChild(el('span', p.label));
    box.appendChild(s);
  }
  function setTab(key, keepSel) {
    cur = progs[key];
    Array.prototype.forEach.call($('tabs').children, function (b) {
      b.setAttribute('aria-selected', b.dataset.k === key ? 'true' : 'false');
    });
    stats();
    runSearch(keepSel);
  }
  function setUrl() {
    if (!cur || !window.history || !history.replaceState) return;
    var u = new URLSearchParams();
    if (cur.key !== 'xb') u.set('v', cur.key);
    if ($('q').value.trim()) u.set('q', $('q').value.trim());
    if ($('state').value) u.set('state', $('state').value);
    if ($('sort').value !== 'addr') u.set('sort', $('sort').value);
    if (mode !== 'size') u.set('map', mode);
    if (sel >= 0) u.set('f', hex(cur.va[sel]));
    var s = u.toString();
    history.replaceState(null, '', s ? '?' + s : location.pathname);
  }

  function start(json) {
    data = json;
    var bins = (json && json.bins) || {};
    ORDER.forEach(function (k) { if (bins[k] && bins[k].s && bins[k].s.length) progs[k] = unpack(k, bins[k]); });
    var keys = ORDER.filter(function (k) { return progs[k]; });
    if (!keys.length) throw new Error('empty map');
    keys.forEach(function (k) {
      var b = el('button', TAB[k], 'tab');
      b.type = 'button';
      b.setAttribute('role', 'tab');
      b.dataset.k = k;
      b.addEventListener('click', function () { if (cur.key !== k) setTab(k, false); });
      $('tabs').appendChild(b);
    });
    var u = new URLSearchParams(location.search);
    if (u.get('q')) $('q').value = u.get('q');
    if (u.get('state') === '0' || u.get('state') === '1') $('state').value = u.get('state');
    if (u.get('sort') === 'small' || u.get('sort') === 'big') $('sort').value = u.get('sort');
    if (u.get('map') === 'count') setMode('count', true);
    $('loading').hidden = true;
    $('explore').hidden = false;
    var first = progs[u.get('v')] ? u.get('v') : keys[0];
    setTab(first, false);
    var f = u.get('f');
    if (f && /^(0x)?[0-9a-fA-F]{1,8}$/.test(f)) {
      var va = parseInt(f.replace(/^0x/i, ''), 16);
      for (var i = 0; i < cur.n; i++) if (cur.va[i] === va) { select(i, true); break; }
    }
  }

  function setMode(m, quiet) {
    mode = m;
    $('by-size').setAttribute('aria-pressed', m === 'size' ? 'true' : 'false');
    $('by-count').setAttribute('aria-pressed', m === 'count' ? 'true' : 'false');
    if (!quiet) { draw(); setUrl(); }
  }
  $('by-size').addEventListener('click', function () { setMode('size'); });
  $('by-count').addEventListener('click', function () { setMode('count'); });
  var timer = null;
  $('q').addEventListener('input', function () { clearTimeout(timer); timer = setTimeout(function () { runSearch(false); }, 180); });
  $('state').addEventListener('change', function () { runSearch(false); });
  $('sort').addEventListener('change', function () { runSearch(true); });
  $('more').addEventListener('click', more);
  $('random').addEventListener('click', randomOpen);
  var rt = null;
  window.addEventListener('resize', function () { clearTimeout(rt); rt = setTimeout(draw, 120); });

  getJson('map.json').then(start).catch(function () {
    $('loading').hidden = true;
    $('missing').hidden = false;
  });
})();
