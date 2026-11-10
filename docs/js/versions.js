// The script of versions.html, kept in its own file so the site's Content-Security-Policy can refuse inline scripts.
(function () {
  'use strict';
  var BASES = ['', 'https://raw.githubusercontent.com/scarface-decomp/scarface_decomp/main/docs/'];
  var PAGE = 200;
  var $ = function (id) { return document.getElementById(id); };
  var fmt = function (n) { return Number(n || 0).toLocaleString('en-US'); };
  var R = null, base = '', changed = null, tab = '', shown = 0, list = [];

  function size(n) {
    var units = ['bytes', 'KB', 'MB', 'GB'], i = 0;
    while (n >= 1024 && i < units.length - 1) { n /= 1024; i++; }
    return i === 0 ? fmt(n) + ' bytes' : n.toFixed(1) + ' ' + units[i];
  }
  function el(tag, text, cls) {
    var e = document.createElement(tag);
    if (text !== undefined) e.textContent = text;
    if (cls) e.className = cls;
    return e;
  }
  function get(url) {
    return fetch(url, { cache: 'no-cache' }).then(function (r) {
      if (!r.ok) throw new Error('HTTP ' + r.status);
      return r.json();
    }).then(function (d) {
      if (!d || d.schema !== 'scarface_versions_v1') throw new Error('not the report');
      return d;
    });
  }
  // The summary from next to this page, or else from the repository; the big list of files that differ
  // comes from the same place, when someone asks for it.
  function load(i) {
    if (i >= BASES.length) return Promise.reject(new Error('not found'));
    return get(BASES[i] + 'versions.json').then(function (d) { base = BASES[i]; return d; },
                                                  function () { return load(i + 1); });
  }
  function loadChanged() {
    if (changed) return Promise.resolve(changed);
    return get(base + (R.changed_file || 'versions-changed.json')).then(function (d) { changed = d.changed || []; return changed; });
  }
  function label(v) {
    for (var i = 0; i < R.versions.length; i++) if (R.versions[i].id === v) return R.versions[i].label;
    return v;
  }

  function render() {
    var body = $('summary');
    R.versions.forEach(function (v) {
      var tr = el('tr');
      [v.label, fmt(v.files), size(v.bytes), fmt(v.only), fmt(v.changed), fmt(v.shared)].forEach(function (t, i) {
        tr.appendChild(el(i === 0 ? 'th' : 'td', t));
      });
      tr.firstChild.setAttribute('scope', 'row');
      body.appendChild(tr);
    });
    $('made').textContent = 'Compared on ' + R.generated + '.';
    Object.keys(R.kinds).forEach(function (k) {
      var o = el('option', R.kinds[k]);
      o.value = k;
      $('kind').appendChild(o);
    });
    R.versions.forEach(function (v, i) {
      var b = el('button', v.label, 'tab');
      b.type = 'button';
      b.setAttribute('role', 'tab');
      b.addEventListener('click', function () { pick(v.id); });
      $('tabs').appendChild(b);
      if (i === 0) tab = v.id;
    });
    var want = (location.hash || '').slice(1);
    if (want && R.versions.some(function (v) { return v.id === want; })) tab = want;
    pick(tab);
  }

  function pick(v) {
    tab = v;
    Array.prototype.forEach.call($('tabs').children, function (b, i) {
      b.setAttribute('aria-selected', R.versions[i].id === v ? 'true' : 'false');
    });
    if (history.replaceState) history.replaceState(null, '', '#' + v);
    filter();
  }

  function filter() {
    var what = $('what').value, kind = $('kind').value, q = $('q').value.trim().toLowerCase();
    if (what === 'changed' && !changed) {
      $('rows').textContent = '';
      $('more').hidden = true;
      $('count').textContent = 'Loading the files that differ…';
      loadChanged().then(filter, function () { $('count').textContent = 'Couldn\'t load the list of files that differ.'; });
      return;
    }
    if (what === 'only') {
      list = (R.only[tab] || []).filter(function (f) {
        return (!kind || f[2] === kind) && (!q || f[0].toLowerCase().indexOf(q) >= 0 || (f[3] || '').toLowerCase().indexOf(q) >= 0);
      });
    } else {
      list = changed.filter(function (c) {
        var mine = c[3].some(function (x) { return x[0] === tab; });
        if (!mine || (kind && c[1] !== kind)) return false;
        return !q || (c[0] + ' ' + c[2] + ' ' + c[3].map(function (x) { return x[2]; }).join(' ')).toLowerCase().indexOf(q) >= 0;
      });
    }
    $('rows').textContent = '';
    shown = 0;
    more();
  }

  function more() {
    var box = $('rows'), what = $('what').value;
    list.slice(shown, shown + PAGE).forEach(function (f) {
      var row = el('div', undefined, 'row');
      if (what === 'only') {
        row.appendChild(el('span', f[0], 'p'));
        row.appendChild(el('span', R.kinds[f[2]] || f[2], 'k'));
        row.appendChild(el('span', size(f[1]), 'z'));
        if (f[3]) row.appendChild(el('span', f[3], 'd'));
      } else {
        row.appendChild(el('span', f[0], 'p'));
        row.appendChild(el('span', R.kinds[f[1]] || f[1], 'k'));
        row.appendChild(el('span', '', 'z'));
        if (f[2]) row.appendChild(el('span', f[2], 'd'));
        var ul = el('ul');
        f[3].forEach(function (x) {
          var li = el('li');
          li.appendChild(el('b', label(x[0])));
          li.appendChild(document.createTextNode(': ' + size(x[1]) + (x[2] ? ', ' + x[2] : '')));
          ul.appendChild(li);
        });
        row.appendChild(ul);
      }
      box.appendChild(row);
    });
    shown = Math.min(list.length, shown + PAGE);
    if (!list.length) box.appendChild(el('div', 'Nothing matches.', 'empty'));
    $('count').textContent = fmt(list.length) + (list.length === 1 ? ' file' : ' files') + (shown < list.length ? ', showing ' + fmt(shown) : '');
    $('more').hidden = shown >= list.length;
  }

  var timer = null;
  $('q').addEventListener('input', function () { clearTimeout(timer); timer = setTimeout(filter, 200); });
  $('what').addEventListener('change', filter);
  $('kind').addEventListener('change', filter);
  $('more').addEventListener('click', more);

  load(0).then(function (d) {
    R = d;
    $('loading').hidden = true;
    $('report').hidden = false;
    render();
  }, function () {
    $('loading').hidden = true;
    $('missing').hidden = false;
  });
})();
