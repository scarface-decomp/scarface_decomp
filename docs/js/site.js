// The script of index.html, kept in its own file so the site's Content-Security-Policy can refuse inline scripts.
(function () {
  'use strict';

  // Where the numbers come from, in order:
  //   1. data/ next to this page: the Cloudflare Pages build copies reports/progress.json there on every push;
  //   2. the repository itself on raw.githubusercontent.com (GitHub Pages, or if 1 is missing).
  // The list of rebuilt functions is functions.json beside this page (made by portal/tools/registry_outputs.py),
  // or the repository's docs/ folder. It has no code: each function links to its lines on GitHub, so the page
  // stays quick however many functions are rebuilt. On a *.github.io address the repository is taken from the
  // address. For local testing only, ?data=<base url> is honoured on localhost and replaces all of them.
  var CFG = (function () {
    var owner = 'scarface-decomp', repo = 'scarface_decomp', branch = 'main';
    var host = location.hostname;
    if (/\.github\.io$/i.test(host)) {
      owner = host.split('.')[0];
      var seg = location.pathname.split('/').filter(Boolean)[0];
      if (seg) repo = seg;
    }
    var raw = 'https://raw.githubusercontent.com/' + owner + '/' + repo + '/' + branch + '/';
    var sources = ['data/', raw + 'reports/'], site = ['', raw + 'docs/'];
    var q = new URLSearchParams(location.search).get('data');
    if (host === 'localhost' && q) sources = site = [q.replace(/\/?$/, '/')];
    return { owner: owner, repo: repo, branch: branch, sources: sources, site: site, repoUrl: 'https://github.com/' + owner + '/' + repo };
  })();

  var $ = function (id) { return document.getElementById(id); };
  var fmt = function (n) { return Number(n || 0).toLocaleString('en-US'); };
  var pct = function (a, b) { return b > 0 ? (a / b) * 100 : 0; };
  var fmtPct = function (p) { return p === 0 ? '0' : p >= 10 ? p.toFixed(1) : p.toFixed(2); };
  var BIN_LABEL = { pc: 'PC', xb: 'Xbox', proto: 'Proto', ps2: 'PS2' };
  // The PS2 program's code overlays (ps2pause, ps2exotics, ...) count as the PS2 version.
  var PS2_BINS = ['ps2', 'ps2pause', 'ps2exotics', 'ps2modals', 'ps2modals1', 'ps2modals2', 'ps2games'];
  PS2_BINS.forEach(function (b) { if (!BIN_LABEL[b]) BIN_LABEL[b] = 'PS2'; });
  var SOURCE_FILE = { pc: 'Original_Binary_Order_PC_1002.cpp', xb: 'Original_Binary_Order_Xbox.cpp',
                      proto: 'Original_Binary_Order_Proto.cpp', ps2: 'Original_Binary_Order_PS2.cpp',
                      ps2pause: 'Original_Binary_Order_PS2_PauseMenu.cpp', ps2exotics: 'Original_Binary_Order_PS2_Exotics.cpp',
                      ps2modals: 'Original_Binary_Order_PS2_Modals.cpp', ps2modals1: 'Original_Binary_Order_PS2_Modals1.cpp',
                      ps2modals2: 'Original_Binary_Order_PS2_Modals2.cpp', ps2games: 'Original_Binary_Order_PS2_MiniGames.cpp' };

  function applyRepoLinks() {
    document.querySelectorAll('a[data-repo-link]').forEach(function (a) {
      a.href = CFG.repoUrl + (a.getAttribute('data-repo-link') || '');
    });
    document.querySelectorAll('[data-repo-text="clone"]').forEach(function (el) { el.textContent = CFG.repoUrl + '.git'; });
  }

  function fetchJson(url) {
    return fetch(url, { cache: 'no-cache' }).then(function (r) {
      if (!r.ok) throw new Error('HTTP ' + r.status);
      return r.text();
    }).then(function (text) {
      return JSON.parse(text);      // an HTML fallback page (single-page-app routing) fails here
    });
  }

  // Try each source in turn.
  var activeSource = null;
  function getJson(name, sources) {
    var list = sources || CFG.sources;
    var i = 0;
    function next(err) {
      if (i >= list.length) return Promise.reject(err || new Error(name + ' not found'));
      var base = list[i++];
      return fetchJson(base + name).then(function (data) { if (!sources) activeSource = base; return data; }, next);
    }
    return next();
  }

  function setBar(id, p) {
    var el = $(id);
    if (el) el.style.width = Math.max(0, Math.min(100, p)).toFixed(2) + '%';
  }

  // ------------------------------------------------------------------ progress
  // ------------------------------------------------------------------ matched over time
  // Drawn from the registry itself: every match carries the time it was verified, so the line for a day is
  // how many of today's matches had been verified by its end. Lines: the released game (Xbox and PC, the
  // headline), the PS2 and the prototype, each only once it has a match. Colours are fixed per line.
  var HISTORY_LINES = [
    { id: 'released', label: 'Released game (Xbox + PC)', bins: ['xb', 'pc'], color: 'var(--s-released)' },
    { id: 'ps2', label: 'PS2', bins: PS2_BINS, color: 'var(--s-ps2)' },
    { id: 'proto', label: 'Xbox prototype', bins: ['proto'], color: 'var(--s-proto)' }
  ];
  var MONTHS = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];
  function dayOf(stamp) {
    var m = /^(\d{4})-(\d\d)-(\d\d)/.exec(stamp || '');
    return m ? Date.UTC(+m[1], +m[2] - 1, +m[3]) / 86400000 : null;
  }
  function dayLabel(day, withYear) {
    var d = new Date(day * 86400000);
    return d.getUTCDate() + ' ' + MONTHS[d.getUTCMonth()] + (withYear ? ' ' + d.getUTCFullYear() : '');
  }
  // The top of the scale: four equal steps of a whole, round number (1, 2, 5, 10, 20, 25, 50, ...).
  function niceStep(top) {
    var raw = Math.max(1, top / 4), p = Math.pow(10, Math.floor(Math.log10(raw))), f = raw / p;
    return Math.max(1, (f <= 1 ? 1 : f <= 2 ? 2 : f <= 2.5 ? 2.5 : f <= 5 ? 5 : 10) * p);
  }
  function historySeries(reg) {
    var entries = Object.values((reg && reg.entries) || {});
    var start = dayOf(reg && reg.reset && reg.reset.date);
    var days = entries.map(function (e) { return dayOf(e.verified_at || e.reverified_at); }).filter(function (d) { return d !== null; });
    var today = Math.floor(Date.now() / 86400000);
    if (start === null) start = days.length ? Math.min.apply(null, days) : today;
    var end = Math.max(today, days.length ? Math.max.apply(null, days) : start, start);
    var lines = HISTORY_LINES.map(function (l) {
      var perDay = {}, total = 0;
      entries.forEach(function (e) {
        if (l.bins.indexOf(e.bin) < 0) return;
        var d = dayOf(e.verified_at || e.reverified_at);
        d = d === null ? start : Math.max(d, start);
        perDay[d] = (perDay[d] || 0) + 1;
        total++;
      });
      var run = 0, values = [];
      for (var d = start; d <= end; d++) { run += perDay[d] || 0; values.push(run); }
      return { line: l, values: values, total: total };
    }).filter(function (s) { return s.total > 0; });
    return { start: start, end: end, lines: lines };
  }

  function svgEl(name, attrs, parent) {
    var e = document.createElementNS('http://www.w3.org/2000/svg', name);
    Object.keys(attrs || {}).forEach(function (k) { e.setAttribute(k, attrs[k]); });
    if (parent) parent.appendChild(e);
    return e;
  }

  var historyReg = null, historyWidth = 0;
  window.addEventListener('resize', function () {
    var w = $('history-plot') && $('history-plot').clientWidth;
    if (historyReg && w && Math.abs(w - historyWidth) > 8) renderHistory(historyReg);
  });

  function renderHistory(reg) {
    historyReg = reg;
    var h = historySeries(reg);
    if (!h.lines.length) return;                       // the chart starts with the first match
    $('history').hidden = false;
    historyWidth = $('history-plot').clientWidth;
    var n = h.end - h.start + 1;
    var multi = h.lines.length > 1;
    $('history-sub').textContent = (multi ? 'Functions matched in each version' : 'Functions matched in the released game (Xbox and PC)') +
      ', counted from the day each was verified, since the checks started again from scratch on ' + dayLabel(h.start, true) + '.';

    // the legend: only when there are two or more lines (one line is named by the text above)
    var legend = $('history-legend');
    legend.textContent = '';
    legend.hidden = !multi;
    h.lines.forEach(function (s) {
      var li = document.createElement('li');
      var key = document.createElement('span');
      key.className = 'h-key';
      key.style.background = s.line.color;
      li.appendChild(key);
      li.appendChild(document.createTextNode(s.line.label));
      legend.appendChild(li);
    });

    // drawn at the size it is shown, so the text stays readable on a phone (redrawn when that changes)
    var svg = $('history-svg');
    var W = Math.max(300, Math.round($('history-plot').clientWidth || 1040));
    var narrow = W < 640;
    var H = narrow ? 240 : 300, M = { t: 14, r: narrow ? 74 : 150, b: 34, l: narrow ? 40 : 52 };
    svg.setAttribute('viewBox', '0 0 ' + W + ' ' + H);
    svg.setAttribute('width', W);
    svg.setAttribute('height', H);
    svg.textContent = '';
    var top = Math.max.apply(null, h.lines.map(function (s) { return s.values[s.values.length - 1]; }));
    var ystep = niceStep(top), ymax = ystep * 4;
    var x = function (i) { return M.l + (n > 1 ? i * (W - M.l - M.r) / (n - 1) : (W - M.l - M.r) / 2); };
    var y = function (v) { return H - M.b - v / ymax * (H - M.t - M.b); };

    // recessive grid: hairlines, four steps, clean numbers
    for (var k = 0; k <= 4; k++) {
      var val = ystep * k;
      svgEl('line', { x1: M.l, x2: W - M.r, y1: y(val), y2: y(val), stroke: k ? 'var(--grid)' : 'var(--axis)', 'stroke-width': 1 }, svg);
      var t = svgEl('text', { x: M.l - 10, y: y(val) + 4, 'text-anchor': 'end', class: 'tick' }, svg);
      t.textContent = val >= 10000 ? fmt(val / 1000) + 'K' : fmt(val);
    }
    // dates along the bottom: about five, never crowded
    var step = Math.max(1, Math.ceil((n - 1) / (narrow ? 3 : 5)));
    for (var i = 0; i < n; i += step) {
      var dt = svgEl('text', { x: x(i), y: H - 10, 'text-anchor': n === 1 ? 'middle' : i === 0 ? 'start' : 'middle', class: 'tick' }, svg);
      dt.textContent = dayLabel(h.start + i, i === 0);
    }
    if ((n - 1) % step !== 0 && n > 1) {
      var last = svgEl('text', { x: x(n - 1), y: H - 10, 'text-anchor': 'end', class: 'tick' }, svg);
      last.textContent = dayLabel(h.end, false);
    }

    // the lines (2px, round), then an end dot with a surface ring and a direct label
    var ends = [];
    h.lines.forEach(function (s) {
      var d = s.values.map(function (v, i) { return (i ? 'L' : 'M') + x(i).toFixed(1) + ' ' + y(v).toFixed(1); }).join(' ');
      if (n > 1) svgEl('path', { d: d, fill: 'none', stroke: s.line.color, 'stroke-width': 2, 'stroke-linejoin': 'round', 'stroke-linecap': 'round' }, svg);
      var v = s.values[n - 1];
      svgEl('circle', { cx: x(n - 1), cy: y(v), r: 5, fill: s.line.color, stroke: '#121212', 'stroke-width': 2 }, svg);
      ends.push({ s: s, y: y(v), v: v });
    });
    // direct labels at the line ends, unless two would collide (then the legend and the tooltip carry them)
    ends.sort(function (a, b) { return a.y - b.y; });
    var clash = ends.some(function (e, i) { return i && e.y - ends[i - 1].y < 30; });
    if (!clash) {
      ends.forEach(function (e) {
        var tv = svgEl('text', { x: x(n - 1) + 12, y: e.y - 1, class: 'end' }, svg);
        tv.textContent = fmt(e.v);
        var tn = svgEl('text', { x: x(n - 1) + 12, y: e.y + 14, class: 'end-sub' }, svg);
        tn.textContent = multi ? e.s.line.label.replace(' (Xbox + PC)', '').replace('Xbox prototype', 'Prototype') : 'functions';
      });
    }

    // hover and keyboard: a crosshair that snaps to the nearest day, one tooltip with every line
    var cross = svgEl('line', { y1: M.t, y2: H - M.b, stroke: 'var(--grey)', 'stroke-width': 1, visibility: 'hidden' }, svg);
    var dots = h.lines.map(function (s) {
      return svgEl('circle', { r: 4, fill: s.line.color, stroke: '#121212', 'stroke-width': 2, visibility: 'hidden' }, svg);
    });
    var hit = svgEl('rect', { x: M.l - 8, y: 0, width: W - M.l - M.r + 16, height: H, fill: 'transparent' }, svg);
    var tip = $('history-tip');
    var at = n - 1;
    function show(i) {
      at = Math.max(0, Math.min(n - 1, i));
      cross.setAttribute('x1', x(at)); cross.setAttribute('x2', x(at)); cross.setAttribute('visibility', 'visible');
      h.lines.forEach(function (s, j) {
        dots[j].setAttribute('cx', x(at)); dots[j].setAttribute('cy', y(s.values[at])); dots[j].setAttribute('visibility', 'visible');
      });
      tip.textContent = '';
      var head = document.createElement('div');
      head.className = 'd';
      head.textContent = dayLabel(h.start + at, true);
      tip.appendChild(head);
      var spoken = [head.textContent];
      h.lines.forEach(function (s) {
        var r = document.createElement('div');
        r.className = 'r';
        var key = document.createElement('span');
        key.className = 'h-key';
        key.style.background = s.line.color;
        var b = document.createElement('b');
        b.textContent = fmt(s.values[at]);
        var name = document.createElement('span');
        name.textContent = s.line.label;
        r.appendChild(key); r.appendChild(b); r.appendChild(name);
        tip.appendChild(r);
        spoken.push(s.line.label + ': ' + fmt(s.values[at]));
      });
      tip.hidden = false;
      var box = svg.getBoundingClientRect(), scale = box.width / W;
      var px = x(at) * scale, tw = tip.offsetWidth;
      tip.style.left = Math.max(0, Math.min(box.width - tw, px + (px + 14 + tw > box.width ? -tw - 14 : 14))) + 'px';
      tip.style.top = (M.t * scale) + 'px';
      $('history-live').textContent = spoken.join(', ');
    }
    function hide() {
      cross.setAttribute('visibility', 'hidden');
      dots.forEach(function (d) { d.setAttribute('visibility', 'hidden'); });
      tip.hidden = true;
    }
    function nearest(ev) {
      var box = svg.getBoundingClientRect();
      var px = (ev.clientX - box.left) / box.width * W;
      return n > 1 ? Math.round((px - M.l) / ((W - M.l - M.r) / (n - 1))) : 0;
    }
    hit.addEventListener('pointermove', function (ev) { show(nearest(ev)); });
    hit.addEventListener('pointerleave', hide);
    svg.addEventListener('focus', function () { show(at); });
    svg.addEventListener('blur', hide);
    svg.addEventListener('keydown', function (ev) {
      var moves = { ArrowLeft: -1, ArrowRight: 1, Home: -n, End: n };
      if (!(ev.key in moves)) return;
      ev.preventDefault();
      show(at + moves[ev.key]);
    });
    svg.setAttribute('aria-label', 'Line chart of functions matched over time. ' + h.lines.map(function (s) {
      return s.line.label + ': ' + fmt(s.values[n - 1]);
    }).join('; ') + '. Use the left and right arrow keys to read each day.');

    // the same numbers as a table: the first day, every day something changed, and today
    var table = $('history-table');
    table.textContent = '';
    var thead = document.createElement('thead'), hr = document.createElement('tr');
    ['Day'].concat(h.lines.map(function (s) { return s.line.label; })).forEach(function (t) {
      var th = document.createElement('th'); th.scope = 'col'; th.textContent = t; hr.appendChild(th);
    });
    thead.appendChild(hr); table.appendChild(thead);
    var tbody = document.createElement('tbody');
    for (var di = n - 1; di >= 0; di--) {
      var changed = di === 0 || di === n - 1 || h.lines.some(function (s) { return s.values[di] !== s.values[di - 1]; });
      if (!changed) continue;
      var tr = document.createElement('tr');
      var td0 = document.createElement('th'); td0.scope = 'row'; td0.textContent = dayLabel(h.start + di, true); tr.appendChild(td0);
      h.lines.forEach(function (s) { var td = document.createElement('td'); td.textContent = fmt(s.values[di]); tr.appendChild(td); });
      tbody.appendChild(tr);
    }
    table.appendChild(tbody);
  }

  // Small functions with a head start, picked by portal/tools/good_first.py from the work queue.
  function renderGoodFirst(prog) {
    var picks = (prog && prog.good_first) || [];
    var list = $('good-first');
    if (!list || !picks.length) return;
    picks.slice(0, 8).forEach(function (p) {
      var li = document.createElement('li');
      var code = document.createElement('code');
      code.textContent = p.symbol;
      var size = document.createElement('span');
      size.className = 's';
      size.textContent = (BIN_LABEL[p.bin] || p.bin) + ', ' + fmt(p.size) + (p.size === 1 ? ' byte' : ' bytes');
      var why = document.createElement('span');
      why.className = 'w';
      why.textContent = p.why;
      li.appendChild(code); li.appendChild(size); li.appendChild(why);
      list.appendChild(li);
    });
    $('good-first-box').hidden = false;
  }

  function renderProgress(prog, reg) {
    var entries = reg ? Object.values(reg.entries || {}) : [];
    var v = (prog && prog.verified) || { pc: 0, xb: 0, total: entries.length, bytes: 0 };
    var q = (prog && prog.queue) || null;
    var total = v.total + (q ? q.total : 0);
    $('sb-verified').textContent = fmt(v.total);
    $('sb-total').textContent = q ? fmt(total) : 'about 21,000';
    var p = q ? pct(v.total, total) : 0;
    if (q) {
      $('sb-pct').textContent = fmtPct(p) + '%';
      if (p >= 100) $('claim').textContent = 'The world is yours.';
    } else {
      $('claim').textContent = 'The world is becoming yours.';
    }
    $('claim').classList.add('on');
    // let the browser paint the empty line first, so it visibly fills (the page's one animation)
    requestAnimationFrame(function () { requestAnimationFrame(function () { setBar('sb-bar', p); }); });
    $('sb-bar-outer').setAttribute('aria-valuenow', p.toFixed(2));
    $('sb-pc').textContent = fmt(v.pc);
    $('sb-xb').textContent = fmt(v.xb);
    $('sb-bytes').textContent = fmt(v.bytes);
    if (prog && prog.compiler) {
      var m = String(prog.compiler).match(/Version\s+([\d.]+)/);
      $('sb-compiler').textContent = m ? 'cl.exe ' + m[1] : prog.compiler;
    }

    // The prototype (unreleased code) has its own row once it is in the queue; the headline is the released game.
    $('proto-row').hidden = !((v.proto || 0) + (q && q.proto ? q.proto : 0));
    ['pc', 'xb', 'proto', 'ps2'].forEach(function (b) {
      var done = v[b] || 0, left = q ? (q[b] || 0) : 0, all = done + left;
      $(b + '-big').textContent = q ? fmtPct(pct(done, all)) + '%' : fmt(done);
      setBar(b + '-bar', pct(done, all));
      $(b + '-sub').textContent = fmt(done) + ' rebuilt' + (q ? ', ' + fmt(left) + ' to go' : '');
    });

    var buckets = (prog && prog.size_buckets) || {};
    var max = Math.max.apply(null, Object.values(buckets).concat([1]));
    var box = $('buckets');
    box.textContent = '';
    Object.keys(buckets).forEach(function (name) {
      var row = document.createElement('div'); row.className = 'bucket';
      var l = document.createElement('span'); l.className = 'lbl';
      l.textContent = name.replace(/^(\d+)-(\d+)/, '$1\u2013$2').replace(/ B$/, ' bytes');
      var t = document.createElement('span'); t.className = 'track';
      var s = document.createElement('span'); s.style.width = pct(buckets[name], max).toFixed(1) + '%'; t.appendChild(s);
      var n = document.createElement('span'); n.className = 'val'; n.textContent = fmt(buckets[name]);
      row.appendChild(l); row.appendChild(t); row.appendChild(n); box.appendChild(row);
    });

    var leaders = $('leaders');
    leaders.textContent = '';
    var people = Object.entries((prog && prog.contributors) || {});
    people.slice(0, 12).forEach(function (kv) {
      var li = document.createElement('li');
      var w = document.createElement('span'); w.className = 'who'; w.textContent = kv[0];
      var n = document.createElement('span'); n.className = 'n'; n.textContent = fmt(kv[1]);
      li.appendChild(w); li.appendChild(n); leaders.appendChild(li);
    });
    var un = (prog && prog.unattributed) || 0;
    $('contrib-note').textContent = people.length
      ? 'Everyone who rebuilds a function through the portal is credited here.' + (un ? ' The first ' + fmt(un) + ' came from early bulk work and have no name on them.' : '')
      : 'Nobody yet. Your name could be first.';
    if (prog && prog.updated_at) $('updated').textContent = 'Numbers updated ' + prog.updated_at.replace('T', ' ').replace('Z', ' UTC');
  }

  // ------------------------------------------------------------------ functions
  var ALL = [];
  var shown = 0;
  var PAGE = 40;
  var filtered = [];

  function sourcePath(e) {
    if (e.file) return e.file;
    if (!e.source || e.source === 'portal') {
      return 'reconstructed_src/' + (SOURCE_FILE[e.bin] || 'Original_Binary_Order_Proto.cpp');
    }
    return 'reconstructed_src/' + e.source;
  }

  // The function's own lines on GitHub (its class's file, at the lines of its block).
  function codeUrl(e) {
    var u = CFG.repoUrl + '/blob/' + CFG.branch + '/' + sourcePath(e).split('/').map(encodeURIComponent).join('/');
    return e.lines && e.lines.length === 2 ? u + '#L' + e.lines[0] + '-L' + e.lines[1] : u;
  }

  function buildList(reg) {
    ALL = Object.keys(reg.entries || {}).map(function (k) {
      var e = reg.entries[k];
      e.key = k;
      e.vaNum = parseInt(e.va, 16) || 0;
      e.hay = (e.symbol + ' ' + e.va + ' ' + (e.source || '') + ' ' + (e.verified_by || '') + ' ' + (e.what || '')).toLowerCase();
      e.when = e.verified_at || e.reverified_at || '';
      return e;
    });
    applyFilter();
  }

  function applyFilter() {
    var term = $('q').value.trim().toLowerCase();
    var bin = $('bin').value;
    var sort = $('sort').value;
    filtered = ALL.filter(function (e) {
      return (bin === 'all' || e.bin === bin || (bin === 'ps2' && PS2_BINS.indexOf(e.bin) >= 0)) &&
        (!term || e.hay.indexOf(term) !== -1);
    });
    filtered.sort(function (a, b) {
      if (sort === 'size') return b.size - a.size || a.vaNum - b.vaNum;
      if (sort === 'recent') return (b.when > a.when ? 1 : b.when < a.when ? -1 : 0) || a.vaNum - b.vaNum;
      var order = { pc: 0, xb: 1, proto: 2 };
      PS2_BINS.forEach(function (b, i) { order[b] = 3 + i; });
      return ((order[a.bin] || 0) - (order[b.bin] || 0)) || a.vaNum - b.vaNum;
    });
    shown = 0;
    $('fn-list').textContent = '';
    renderMore();
  }

  function renderMore() {
    var list = $('fn-list');
    var slice = filtered.slice(shown, shown + PAGE);
    if (!filtered.length) {
      var em = document.createElement('div'); em.className = 'empty';
      if (ALL.length) {
        em.textContent = 'Nothing rebuilt matches that search yet.';
      } else {
        em.appendChild(document.createTextNode('Nothing rebuilt yet. The first function could be yours: '));
        var go = document.createElement('a'); go.href = '#help'; go.textContent = 'start helping';
        em.appendChild(go); em.appendChild(document.createTextNode('.'));
      }
      list.appendChild(em);
    }
    slice.forEach(function (e) { list.appendChild(row(e)); });
    shown += slice.length;
    $('count').textContent = fmt(filtered.length) + ' function' + (filtered.length === 1 ? '' : 's') + (shown < filtered.length ? ', showing ' + fmt(shown) : '');
    $('more').hidden = shown >= filtered.length;
  }

  function row(e) {
    var item = document.createElement('div'); item.className = 'fn';
    var head = document.createElement('button'); head.type = 'button'; head.className = 'fn-head';
    head.setAttribute('aria-expanded', 'false');
    var tag = document.createElement('span'); tag.className = 'tag ' + e.bin; tag.textContent = BIN_LABEL[e.bin] || e.bin;
    var va = document.createElement('span'); va.className = 'fn-va'; va.textContent = e.va;
    var sym = document.createElement('span'); sym.className = 'fn-sym'; sym.textContent = e.symbol; sym.title = e.symbol;
    var size = document.createElement('span'); size.className = 'fn-size'; size.textContent = e.size + ' B';
    var chev = document.createElement('span'); chev.className = 'chev'; chev.setAttribute('aria-hidden', 'true'); chev.textContent = '›';
    [tag, va, sym, size, chev].forEach(function (n) { head.appendChild(n); });
    var body = document.createElement('div'); body.className = 'fn-body';
    head.addEventListener('click', function () {
      var open = item.classList.toggle('open');
      head.setAttribute('aria-expanded', open ? 'true' : 'false');
      if (open && !body.firstChild) fillBody(body, e);
    });
    item.appendChild(head); item.appendChild(body);
    return item;
  }

  function metaItem(parent, label, value) {
    var s = document.createElement('span');
    s.appendChild(document.createTextNode(label + ' '));
    var b = document.createElement('b'); b.textContent = value; s.appendChild(b);
    parent.appendChild(s);
  }

  function fillBody(body, e) {
    if (e.what) {
      var what = document.createElement('p'); what.className = 'fn-what';
      what.textContent = e.what;
      body.appendChild(what);
    }
    var meta = document.createElement('div'); meta.className = 'meta';
    metaItem(meta, 'Address', e.va);
    metaItem(meta, 'Size', e.size + ' bytes');
    metaItem(meta, 'Compiler flags', e.flags || '');
    metaItem(meta, 'Rebuilt by', e.verified_by || 'early bulk work');
    if (e.tool_used) metaItem(meta, 'Tool', e.tool_used);
    if (e.note) metaItem(meta, 'Note', e.note);
    body.appendChild(meta);
    var links = document.createElement('div'); links.className = 'fn-links';
    var a = document.createElement('a');
    a.href = codeUrl(e);
    a.className = 'code-link';
    a.target = '_blank'; a.rel = 'noopener noreferrer';
    a.textContent = 'Read its C++ on GitHub';
    a.title = sourcePath(e) + (e.lines ? ', lines ' + e.lines[0] + '\u2013' + e.lines[1] : '');
    var own = document.createElement('a');
    own.href = 'function.html?f=' + encodeURIComponent(e.key);
    own.className = 'own';
    own.textContent = 'Its own page';
    links.appendChild(a);
    links.appendChild(document.createTextNode(' · '));
    links.appendChild(own);
    body.appendChild(links);
  }

  var t = null;
  $('q').addEventListener('input', function () { clearTimeout(t); t = setTimeout(applyFilter, 160); });
  $('bin').addEventListener('change', applyFilter);
  $('sort').addEventListener('change', applyFilter);
  $('more').addEventListener('click', renderMore);

  // ------------------------------------------------------------------ contents
  // Mark the section being read, and keep its link in view in the phone-width scrolling row.
  (function () {
    var links = Array.prototype.slice.call(document.querySelectorAll('#toc a'));
    var byId = {};
    links.forEach(function (a) { byId[a.getAttribute('href').slice(1)] = a; });
    var current = null;
    function mark(id) {
      if (id === current) return;
      current = id;
      links.forEach(function (a) { a.removeAttribute('aria-current'); });
      var a = byId[id];
      if (!a) return;
      a.setAttribute('aria-current', 'true');
      var toc = $('toc');
      if (toc.scrollWidth > toc.clientWidth) {
        var left = a.offsetLeft - (toc.clientWidth - a.offsetWidth) / 2;
        toc.scrollTo({ left: Math.max(0, left), behavior: 'smooth' });
      }
    }
    var sections = Object.keys(byId).map(function (id) { return document.getElementById(id); }).filter(Boolean);
    function update() {
      var line = window.innerHeight * 0.35, best = null;
      sections.forEach(function (sec) { if (sec.getBoundingClientRect().top <= line) best = sec.id; });
      if (window.innerHeight + window.scrollY >= document.documentElement.scrollHeight - 2) best = sections[sections.length - 1].id;
      mark(best);
    }
    var queued = false;
    window.addEventListener('scroll', function () {
      if (queued) return;
      queued = true;
      requestAnimationFrame(function () { queued = false; update(); });
    }, { passive: true });
    window.addEventListener('resize', update);
    update();
  })();

  // ------------------------------------------------------------------ load
  applyRepoLinks();
  // haveNumbers: the scoreboard loaded, only the list of functions didn't.
  function showUnavailable(err, haveNumbers) {
    var status = $('data-status');
    status.className = 'status-line err';
    status.textContent = (haveNumbers ? 'The list of rebuilt functions' : 'The latest numbers') + ' could not be loaded (' +
      (err && err.message ? err.message : 'network error') + '). Try again in a minute.';
    if (!haveNumbers) $('claim').textContent = 'The world is yours.';
    var list = $('fn-list');
    list.textContent = '';
    var em = document.createElement('div'); em.className = 'empty'; em.textContent = 'The function list could not be loaded right now.';
    list.appendChild(em);
  }

  // ------------------------------------------------------------------ for the curious
  // Rage mode: the classic code (up up down down left right left right B A), or five quick taps on
  // the name in the top bar on a phone.
  (function () {
    var seq = ['ArrowUp', 'ArrowUp', 'ArrowDown', 'ArrowDown', 'ArrowLeft', 'ArrowRight', 'ArrowLeft', 'ArrowRight', 'b', 'a'];
    var pos = 0, busy = false, taps = [];
    function rage() {
      if (busy) return;
      busy = true;
      var veil = document.createElement('div'); veil.className = 'rage-veil';
      var sign = document.createElement('div'); sign.className = 'rage-sign'; sign.setAttribute('role', 'status');
      sign.innerHTML = 'RAGE<small>Unlimited ammo for four seconds. Spend it on a function.</small>';
      document.body.appendChild(veil); document.body.appendChild(sign);
      requestAnimationFrame(function () { veil.classList.add('on'); sign.classList.add('on'); document.querySelector('main').classList.add('shake'); });
      setTimeout(function () { veil.classList.remove('on'); sign.classList.remove('on'); document.querySelector('main').classList.remove('shake'); }, 4000);
      setTimeout(function () { veil.remove(); sign.remove(); busy = false; }, 4600);
    }
    document.addEventListener('keydown', function (e) {
      var t = e.target;
      if (t && (t.isContentEditable || /^(INPUT|TEXTAREA|SELECT)$/.test(t.tagName))) return;   // not while typing a search
      var k = e.key.length === 1 ? e.key.toLowerCase() : e.key;
      pos = k === seq[pos] ? pos + 1 : (k === seq[0] ? 1 : 0);
      if (pos === seq.length) { pos = 0; rage(); }
    });
    document.querySelector('.brand').addEventListener('click', function () {
      var now = Date.now();
      taps = taps.filter(function (t) { return now - t < 1600; }).concat(now);
      if (taps.length >= 5) { taps = []; rage(); }
    });
    if (window.console && console.log) {
      console.log('%cThe world is yours.', 'font: 28px Anton, Impact, sans-serif; color: #EA444D; text-transform: uppercase;');
      console.log('Reading the source? You would be good at this. Pick a function: ' + CFG.repoUrl + '/blob/main/docs/CONTRIBUTING.md' +
                  '\n(And try the old up-up-down-down code on this page.)');
    }
  })();

  // The scoreboard first (a small file), then the list of rebuilt functions, which doesn't hold it up.
  var progress = getJson('progress.json').then(function (prog) {
    renderProgress(prog, null);
    renderGoodFirst(prog);
    return prog;
  }, function () { return null; });
  getJson('functions.json', CFG.site).then(function (reg) {
    return progress.then(function (prog) {
      if (!prog) renderProgress(null, reg);
      renderHistory(reg);
      buildList(reg);
      $('data-status').textContent = 'Live numbers from ' + CFG.owner + '/' + CFG.repo +
        (!prog || activeSource === 'data/' ? ' (latest deploy)' : ' on GitHub') +
        (prog ? '' : '; the summary file is missing, so only the function list is shown') + '.';
    });
  }, function (err) {
    progress.then(function (prog) { showUnavailable(err, !!prog); });
  });
})();
