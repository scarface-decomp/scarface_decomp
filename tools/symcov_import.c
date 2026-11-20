/*
 * symcov_import: use a symcov report of default.xbe in the project's lists.
 *
 *   build\symcov_import --csv E:\...\scarface_xbox\matches.csv            (dry run: counts only)
 *   build\symcov_import --csv ... --list                                  (one line per row and what became of it)
 *   build\symcov_import --csv ... --write                                 (edit reports/ in place)
 *   build\symcov_import --csv ... --emit DIR                              (write the edited files under DIR/reports/)
 *
 * Run it from the repository root, or pass --repo. It is safe to run again: a second run finds nothing new.
 *
 * The input. matches.csv lists functions of default.xbe whose code is identical (addresses apart) to a named
 * function in another game's build (docs/NAMES.md, AGENTS.md rulings 1 and 2). A name from another game's
 * debug symbols is evidence, not a Scarface name: for Microsoft's library code it is the function's own name,
 * for the game's code it is only a hint to what the code does. The reports were made from a copy of the xbe
 * that differs from binaries/default.xbe in one byte (offset 0x22C458); the addresses are the same.
 *
 * What it reads. reconstructed_src/Original_Binary_Order_Xbox.cpp (the [TODO] and [VERIFIED] lines: what the
 * project lists), reports/library_functions.json, reports/extra_function_starts.json, reports/names.json,
 * reports/known_functions.json and binaries/default.xbe.
 *
 * What it does (the numbers are printed at the end):
 *
 *  1. Library reclassification. A queued .text function goes into reports/library_functions.json
 *     (functions.xb) when its name is Microsoft's (C runtime, XAPILIB, the C++ run time, XGRAPHICS) AND its
 *     address lies in a block of library code: an unbroken run of functions (no gap over 0x40 bytes, using
 *     the project's own list of starts and sizes) that holds at least 4 functions already listed as library
 *     code. Third-party code inside such a run is not moved: RAD Game Tools' Bink audio code and the Ooura
 *     FFT it contains (_cft*, _makewt, _rdft ...), see THIRD_PARTY below. zlib, libpng, STL instantiations
 *     and the game's own code stay in the queue.
 *  2. Missing function starts. An .text row the project does not list is checked against the binary with the
 *     project's own rules (portal/tools/sf_binaries.py: function_extent, not_compiled_reason, settle_overlaps).
 *     It is a real start when it is not inside a listed or verified function, follows a return, a tail jump
 *     or padding, is measured by the walk as the report's size (when the report's size was only inferred: no
 *     longer than it), does not run over the next listed start, and survives the queue build's own cover rule
 *     (a start inside the measured extent of an earlier start is dropped by queue_builder, so it is not added). A real start in a library block goes to
 *     the library list, any other to reports/extra_function_starts.json. Nothing listed is resized or dropped.
 *     The measuring is done by python (capstone is the project's disassembler): the tool pipes the few lines
 *     of python it needs (BRIDGE below) into `python -`, there is no separate python tool.
 *  3. Names (reports/names.json), only for a function that has none, only when the report names exactly one
 *     function for that code ("unique"), and only for
 *       - Microsoft library code: .text functions of 1 and 2, and every function of the library sections
 *         (D3D, D3DX, XGRPH, DSOUND, WMADEC, XPP);
 *       - public open-source code whose surrounding code is that library: zlib (the program holds "inflate
 *         1.2.1 Copyright"), libpng ("libpng version"), the Ooura FFT run of the Bink audio code.
 *     by is "symcov: <build the name comes from>". The name is the library's own: _ReadFile@20 becomes
 *     ReadFile, __input becomes _input (the report lists the decorated and the plain form; where it lists
 *     only one, one leading underscore and the @N are taken off). A name that is not an ordinary C++ name,
 *     is already recorded, or would be given to two functions is skipped. Names for starts that are not yet
 *     in the address-order list (new zlib starts) wait: they are written to the hints file as "name_pending"
 *     and a second run, after `python portal/tools/registry_outputs.py` lists them, adds them.
 *  4. Hints (reports/symcov_hints.json): for open functions that are not named above, the report's name as
 *     what the code does, never as a Scarface name. Fields: hint, build, choice (unique | link-order),
 *     candidates, size, kind (game | third-party).
 *     Compiler-made names ($E12, _$E3, $$$00001) say nothing and are not recorded.
 *
 * Rows it leaves alone, with the reason, are counted and (with --list) shown. "link-order" rows (the same
 * code appears under several names, the report assigns them by link order) are moved or hinted but never
 * named: which of the identical names belongs to which copy is a guess.
 *
 * Not done by this tool: it never edits reconstructed_src/ (generated): after --write run
 * `python portal/tools/registry_outputs.py` to bring the address-order lists and counts up to date.
 */

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#ifdef _WIN32
#include <direct.h>
#define MKDIR(p) _mkdir(p)
#define POPEN _popen
#define PCLOSE _pclose
#else
#include <sys/stat.h>
#define MKDIR(p) mkdir(p, 0777)
#define POPEN popen
#define PCLOSE pclose
#endif
#if defined(_MSC_VER) && _MSC_VER < 1900
#define snprintf _snprintf
#endif

/* ------------------------------------------------------------------------------------------ util */

static void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "symcov_import: ");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
    exit(2);
}

static void *xmalloc(size_t n)
{
    void *p = malloc(n ? n : 1);
    if (!p) die("out of memory");
    return p;
}

static void *xrealloc(void *p, size_t n)
{
    p = realloc(p, n ? n : 1);
    if (!p) die("out of memory");
    return p;
}

static char *xstrdup(const char *s)
{
    size_t n = strlen(s) + 1;
    char *p = (char *)xmalloc(n);
    memcpy(p, s, n);
    return p;
}

static char *read_file(const char *path, size_t *len)
{
    FILE *f = fopen(path, "rb");
    char *buf;
    long n;
    if (!f)
        return NULL;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = (char *)xmalloc((size_t)n + 1);
    if (fread(buf, 1, (size_t)n, f) != (size_t)n)
        die("cannot read %s", path);
    fclose(f);
    buf[n] = 0;
    if (len)
        *len = (size_t)n;
    return buf;
}

typedef struct { char *p; size_t n, cap; } Buf;

static void buf_add(Buf *b, const char *s, size_t n)
{
    if (b->n + n + 1 > b->cap)
    {
        b->cap = (b->n + n + 1) * 2 + 256;
        b->p = (char *)xrealloc(b->p, b->cap);
    }
    memcpy(b->p + b->n, s, n);
    b->n += n;
    b->p[b->n] = 0;
}

static void buf_puts(Buf *b, const char *s)
{
    buf_add(b, s, strlen(s));
}

static void buf_addf(Buf *b, const char *fmt, ...)
{
    char tmp[16384];
    va_list ap;
    int n;
    va_start(ap, fmt);
    n = vsnprintf(tmp, sizeof tmp, fmt, ap);
    va_end(ap);
    if (n < 0 || n >= (int)sizeof tmp)
        n = (int)sizeof tmp - 1;
    buf_add(b, tmp, (size_t)n);
}

/* a JSON string body: backslash and quote escaped, the rest is ASCII here */
static void buf_json(Buf *b, const char *s)
{
    for (; *s; s++)
    {
        if (*s == '"' || *s == '\\')
            buf_add(b, "\\", 1);
        if ((unsigned char)*s < 0x20)
            continue;
        buf_add(b, s, 1);
    }
}

static void make_dirs_for(const char *path)
{
    char tmp[1024];
    char *p;
    snprintf(tmp, sizeof tmp, "%s", path);
    for (p = tmp + 1; *p; p++)
        if (*p == '/' || *p == '\\')
        {
            char c = *p;
            *p = 0;
            MKDIR(tmp);
            *p = c;
        }
}

static void write_file(const char *path, const char *data, size_t n)
{
    FILE *f;
    make_dirs_for(path);
    f = fopen(path, "wb");
    if (!f)
        die("cannot write %s", path);
    fwrite(data, 1, n, f);
    fclose(f);
}

/* sorted array of unsigned */
typedef struct { unsigned *v; int n, cap; } UL;

static void ul_add(UL *l, unsigned x)
{
    if (l->n == l->cap)
    {
        l->cap = l->cap ? l->cap * 2 : 256;
        l->v = (unsigned *)xrealloc(l->v, (size_t)l->cap * sizeof(unsigned));
    }
    l->v[l->n++] = x;
}

static int cmp_u(const void *a, const void *b)
{
    unsigned x = *(const unsigned *)a, y = *(const unsigned *)b;
    return x < y ? -1 : x > y;
}

static void ul_sort(UL *l)
{
    int i, j = 0;
    qsort(l->v, (size_t)l->n, sizeof(unsigned), cmp_u);
    for (i = 0; i < l->n; i++)
        if (i == 0 || l->v[i] != l->v[i - 1])
            l->v[j++] = l->v[i];
    l->n = j;
}

static int ul_has(const UL *l, unsigned x)
{
    return l->n && bsearch(&x, l->v, (size_t)l->n, sizeof(unsigned), cmp_u) != NULL;
}

/* ---------------------------------------------------------------------------------- the lists */

typedef struct { unsigned va; int size; char kind; } Fn;   /* kind: D verified, T queued, L library, X extra, N new */

static Fn *fns;
static int nfns, capfns;

static void fn_add(unsigned va, int size, char kind)
{
    if (nfns == capfns)
    {
        capfns = capfns ? capfns * 2 : 4096;
        fns = (Fn *)xrealloc(fns, (size_t)capfns * sizeof(Fn));
    }
    fns[nfns].va = va;
    fns[nfns].size = size;
    fns[nfns].kind = kind;
    nfns++;
}

static int cmp_fn(const void *a, const void *b)
{
    const Fn *x = (const Fn *)a, *y = (const Fn *)b;
    if (x->va != y->va)
        return x->va < y->va ? -1 : 1;
    return (int)x->kind - (int)y->kind;
}

static Fn *fn_find(unsigned va)
{
    Fn key;
    key.va = va;
    key.kind = 0;
    {
        int lo = 0, hi = nfns - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (fns[mid].va < va)
                lo = mid + 1;
            else if (fns[mid].va > va)
                hi = mid - 1;
            else
            {
                while (mid > 0 && fns[mid - 1].va == va)
                    mid--;
                return &fns[mid];
            }
        }
    }
    return NULL;
}

/* symbols of verified functions: a name other than sub_XXXXXXXX is a name already */
static UL verified_named;
static UL lib_list, lib_sections, extra_list, todo_list, done_list, name_symcov;

static void load_listing(const char *path)
{
    size_t len;
    char *text = read_file(path, &len);
    char *line, *next;
    if (!text)
        die("%s is not there: run from the repository root or pass --repo", path);
    for (line = text; line && *line; line = next)
    {
        char *eol = strchr(line, '\n');
        unsigned va;
        int size;
        next = eol ? eol + 1 : NULL;
        if (eol)
            *eol = 0;
        if (eol && eol > line && eol[-1] == '\r')
            eol[-1] = 0;
        if (strncmp(line, "// [TODO] 0x", 12) == 0)
        {
            char *par = strrchr(line, '(');
            if (par && sscanf(line + 12, "%x", &va) == 1 && sscanf(par, "(%d B)", &size) == 1)
            {
                fn_add(va, size, 'T');
                ul_add(&todo_list, va);
            }
        }
        else if (strncmp(line, "// [VERIFIED] ", 14) == 0)
        {
            char *par = strrchr(line, '(');
            if (par && sscanf(par, "(0x%x, %d B)", &va, &size) == 2)
            {
                fn_add(va, size, 'D');
                ul_add(&done_list, va);
                if (strncmp(line + 14, "sub_", 4) != 0)
                    ul_add(&verified_named, va);
            }
        }
    }
    free(text);
    ul_sort(&todo_list);
    ul_sort(&done_list);
    ul_sort(&verified_named);
}

/* the "xb" array under a given key of a JSON file made by json.dumps(indent=...): found by text, so the
 * rest of the file is kept byte for byte */
typedef struct { size_t open, close; } Span;      /* offsets of '[' and ']' */

static int find_array(const char *text, const char *section, const char *key, Span *sp)
{
    const char *s = strstr(text, section);
    const char *k, *o, *c;
    if (!s)
        return 0;
    k = strstr(s, key);
    if (!k)
        return 0;
    o = strchr(k, '[');
    c = o ? strchr(o, ']') : NULL;
    if (!c)
        return 0;
    sp->open = (size_t)(o - text);
    sp->close = (size_t)(c - text);
    return 1;
}

static void parse_hex_array(const char *text, Span sp, UL *out)
{
    size_t i;
    for (i = sp.open; i < sp.close; i++)
        if (text[i] == '"' && text[i + 1] == '0' && text[i + 2] == 'x')
        {
            unsigned v;
            if (sscanf(text + i + 3, "%x", &v) == 1)
                ul_add(out, v);
        }
    ul_sort(out);
}

/* rewrite the array with the given (sorted) addresses, keeping the indentation the file has */
static char *rewrite_array(const char *text, Span sp, const UL *all, size_t *outlen)
{
    Buf b = { 0, 0, 0 };
    size_t i, ws0;
    int k;
    char indent_item[64], indent_close[64];
    size_t n;
    /* indentation of the first item and of the closing bracket */
    for (i = sp.open + 1; i < sp.close && text[i] != '"'; i++)
        ;
    for (ws0 = i; ws0 > 0 && text[ws0 - 1] != '\n'; ws0--)
        ;
    n = i - ws0;
    if (n >= sizeof indent_item)
        n = sizeof indent_item - 1;
    memcpy(indent_item, text + ws0, n);
    indent_item[n] = 0;
    for (ws0 = sp.close; ws0 > 0 && text[ws0 - 1] != '\n'; ws0--)
        ;
    n = sp.close - ws0;
    if (n >= sizeof indent_close)
        n = sizeof indent_close - 1;
    memcpy(indent_close, text + ws0, n);
    indent_close[n] = 0;
    buf_add(&b, text, sp.open + 1);
    for (k = 0; k < all->n; k++)
        buf_addf(&b, "%s%s\"0x%08X\"", k ? ",\n" : "\n", indent_item, all->v[k]);
    buf_addf(&b, "\n%s", indent_close);
    buf_puts(&b, text + sp.close);
    *outlen = b.n;
    return b.p;
}

/* ----------------------------------------------------------------------------------- names.json */

typedef struct { char *s; } Str;
static char **name_of_va;           /* parallel to name_vas */
static UL name_vas;
static char **used_names;           /* every xb name recorded */
static int n_used, cap_used;

static int cmp_str(const void *a, const void *b)
{
    return strcmp(*(char *const *)a, *(char *const *)b);
}

static void load_names(const char *text)
{
    const char *p = text;
    while ((p = strstr(p, "\"xb:0x")) != NULL)
    {
        unsigned va;
        const char *q;
        p += 6;
        if (sscanf(p, "%8x", &va) != 1)
            continue;
        q = strstr(p, "\"name\": \"");
        if (q)
        {
            const char *e = q + 9;
            Buf b = { 0, 0, 0 };
            while (*e && *e != '"')
            {
                if (*e == '\\' && e[1])
                    e++;
                buf_add(&b, e, 1);
                e++;
            }
            ul_add(&name_vas, va);
            {
                /* the "by" of this entry, when it is ours */
                const char *by = strstr(q, "\"by\": \"");
                const char *next = strstr(p, "\"xb:0x");
                if (by && (!next || by < next) && strncmp(by + 7, "symcov: ", 8) == 0)
                    ul_add(&name_symcov, va);
            }
            if (n_used == cap_used)
            {
                cap_used = cap_used ? cap_used * 2 : 4096;
                used_names = (char **)xrealloc(used_names, (size_t)cap_used * sizeof(char *));
            }
            used_names[n_used++] = b.p ? b.p : xstrdup("");
        }
    }
    ul_sort(&name_vas);
    ul_sort(&name_symcov);
    qsort(used_names, (size_t)n_used, sizeof(char *), cmp_str);
}

static int name_used(const char *s)
{
    return n_used && bsearch(&s, used_names, (size_t)n_used, sizeof(char *), cmp_str) != NULL;
}

/* -------------------------------------------------------------------------------------- the csv */

enum { C_ADDR, C_SIZE, C_SECTION, C_NAME, C_FROM, C_NCAND, C_CHOICE, C_ALL, C_PROTOS, C_PADDRS, C_INFER, C_COUNT };

typedef struct
{
    unsigned va;
    int size, ncand, inferred;
    char *section, *name, *from, *choice, *all;
    char cls;            /* D L T X U (unlisted) */
    int accepted;        /* U rows: the boundary check passed */
    char *reject;        /* U rows: why not */
    int bsize;           /* U rows: measured size */
    int in_block;
    char act[16];        /* what was done */
    char note[200];
    int named;           /* a name is being added */
    char *pending;       /* a name that waits for the start to be listed */
    int overlap;         /* outside .text: runs into the row before it */
} Row;

static Row *rows;
static int nrows;

/* one field at *pp: quoted ("" is a quote) or plain; sets *eol when the record ends there */
static char *csv_field(char **pp, int *eol)
{
    char *p = *pp, *start = p, *w;
    *eol = 0;
    if (*p == '"')
    {
        w = start;
        p++;
        for (;;)
        {
            if (!*p)
                break;
            if (*p == '"')
            {
                if (p[1] == '"')
                {
                    *w++ = '"';
                    p += 2;
                    continue;
                }
                p++;
                break;
            }
            *w++ = *p++;
        }
        *w = 0;
        if (*p == ',')
            p++;
        else
        {
            *eol = 1;
            while (*p == '\r' || *p == '\n')
                p++;
        }
    }
    else
    {
        while (*p && *p != ',' && *p != '\r' && *p != '\n')
            p++;
        if (*p == ',')
        {
            *p++ = 0;
        }
        else
        {
            *eol = 1;
            while (*p == '\r' || *p == '\n')
                *p++ = 0;
        }
    }
    *pp = p;
    return start;
}

static void parse_csv(char *buf)
{
    char *p = buf;
    int cap = 0, header = 1;
    while (*p)
    {
        char *f[C_COUNT];
        int field = 0, eol = 0;
        while (field < C_COUNT && !eol)
            f[field++] = csv_field(&p, &eol);
        while (!eol && *p)
            csv_field(&p, &eol);                    /* extra columns */
        while (field < C_COUNT)
            f[field++] = (char *)"";
        if (header)
        {
            header = 0;
            continue;
        }
        if (nrows == cap)
        {
            cap = cap ? cap * 2 : 4096;
            rows = (Row *)xrealloc(rows, (size_t)cap * sizeof(Row));
        }
        memset(&rows[nrows], 0, sizeof(Row));
        rows[nrows].va = (unsigned)strtoul(f[C_ADDR], NULL, 16);
        rows[nrows].size = atoi(f[C_SIZE]);
        rows[nrows].section = f[C_SECTION];
        rows[nrows].name = f[C_NAME];
        rows[nrows].from = f[C_FROM];
        rows[nrows].ncand = atoi(f[C_NCAND]);
        rows[nrows].choice = f[C_CHOICE];
        rows[nrows].all = f[C_ALL];
        rows[nrows].inferred = atoi(f[C_INFER]);
        nrows++;
    }
}

/* "[XBOX] The Red Star (Beta) [2004-07-17] (MAP)/default.xbe@0x49ea0" -> up to the last '@' */
static void build_label(const Row *r, char *out, size_t n)
{
    const char *at = strrchr(r->from, '@');
    size_t len = at ? (size_t)(at - r->from) : strlen(r->from);
    if (len >= n)
        len = n - 1;
    memcpy(out, r->from, len);
    out[len] = 0;
}

/* ---------------------------------------------------------------------------------- name rules */

static int is_id0(int c) { return isalpha(c) || c == '_'; }
static int is_id(int c) { return isalnum(c) || c == '_'; }

/* one part of a C++ name: an identifier with optional <...>; the last part may be operatorX, ~Name */
static int match_part(const char *s, size_t *i, int last)
{
    size_t j = *i;
    if (last && s[j] == '~')
        j++;
    if (last && strncmp(s + j, "operator", 8) == 0 && s[j + 8] && !is_id(s[j + 8]))
    {
        size_t k = j + 8, m = 0;
        while (s[k] && !isspace((unsigned char)s[k]) && m < 3)
            k++, m++;
        if (m >= 1 && !s[k])
        {
            *i = k;
            return 1;
        }
    }
    if (!is_id0((unsigned char)s[j]))
        return 0;
    while (is_id((unsigned char)s[j]))
        j++;
    if (s[j] == '<')
    {
        int depth = 0;
        size_t k = j;
        do
        {
            if (s[k] == '<')
                depth++;
            else if (s[k] == '>')
                depth--;
            else if (!(isalnum((unsigned char)s[k]) || strchr("_:, *&", s[k])))
                return 0;
            k++;
        } while (s[k - 1] && depth > 0);
        if (depth)
            return 0;
        j = k;
    }
    *i = j;
    return 1;
}

static int default_name(const char *last)
{
    const char *p = NULL;
    if (strncmp(last, "sub_", 4) == 0 || strncmp(last, "FUN_", 4) == 0)
        p = last + 4;
    else if (strncmp(last, "func_", 5) == 0)
        p = last + 5;
    else if (strncmp(last, "thunk_", 6) == 0)
        p = last + 6;
    if (!p || !*p)
        return 0;
    for (; *p; p++)
        if (!isxdigit((unsigned char)*p))
            return 0;
    return 1;
}

/* names.py NAME_RE and not DEFAULT_RE */
static int valid_name(const char *s)
{
    size_t i = 0;
    const char *last = s, *c;
    if (!*s)
        return 0;
    for (;;)
    {
        size_t save = i;
        int is_last;
        const char *q = strstr(s + save, "::");
        /* the part is the last one when no "::" follows at depth 0 */
        {
            int depth = 0;
            const char *t;
            q = NULL;
            for (t = s + save; *t; t++)
            {
                if (*t == '<')
                    depth++;
                else if (*t == '>')
                    depth--;
                else if (*t == ':' && t[1] == ':' && depth == 0)
                {
                    q = t;
                    break;
                }
            }
        }
        is_last = (q == NULL);
        if (!match_part(s, &i, is_last))
            return 0;
        if (is_last)
        {
            if (s[i])
                return 0;
            break;
        }
        if (!(s[i] == ':' && s[i + 1] == ':'))
            return 0;
        i += 2;
        last = s + i;
    }
    if (strstr(s, "::"))
    {
        c = last;
        if (default_name(c))
            return 0;
    }
    else if (default_name(s))
        return 0;
    return 1;
}

static const char *base_end(const char *s)       /* where a trailing @digits starts */
{
    size_t n = strlen(s);
    size_t k = n;
    while (k > 0 && isdigit((unsigned char)s[k - 1]))
        k--;
    if (k > 0 && k < n && s[k - 1] == '@')
        return s + k - 1;
    return s + n;
}

static int eq_base(const char *a, const char *b_plain)  /* a without @N equals b_plain */
{
    size_t n = (size_t)(base_end(a) - a);
    return strlen(b_plain) == n && strncmp(a, b_plain, n) == 0;
}

/* the report lists the decorated and the plain form of a C name (_malloc | malloc, __cinit@0 | _cinit): the
 * plain one is the name. With only one form, one leading underscore and @N are taken off. */
static char *plain_c_name(const Row *r)
{
    char alias[512];
    const char *p = r->all;
    char cand[512];
    size_t n = (size_t)(base_end(r->name) - r->name);
    int found = 0;
    if (r->name[0] == '@' || n >= sizeof cand)
        return NULL;
    memcpy(cand, r->name, n);
    cand[n] = 0;
    /* is some other alias the same name with one more underscore (then cand is plain), or is cand the
     * decorated form of some alias (then that alias is plain)? */
    while (p && *p)
    {
        const char *e = strstr(p, " | ");
        size_t len = e ? (size_t)(e - p) : strlen(p);
        if (len < sizeof alias)
        {
            char t[512];
            size_t bl;
            memcpy(alias, p, len);
            alias[len] = 0;
            bl = (size_t)(base_end(alias) - alias);
            memcpy(t, alias, bl);
            t[bl] = 0;
            if (t[0] == '_' && strcmp(t + 1, cand) == 0)
                found = 1;                                     /* cand is plain */
            else if (cand[0] == '_' && strcmp(cand + 1, t) == 0 && !found)
            {
                char *res = xstrdup(t);
                return valid_name(res) ? res : NULL;           /* the alias is plain */
            }
        }
        p = e ? e + 3 : NULL;
    }
    if (found)
        return valid_name(cand) ? xstrdup(cand) : NULL;
    if (cand[0] == '_' && cand[1])
        return valid_name(cand + 1) ? xstrdup(cand + 1) : NULL;
    return valid_name(cand) ? xstrdup(cand) : NULL;
}

/* ?Name@Class@NS@@... -> NS::Class::Name (names_from_xdk_map.plain_name) */
static char *plain_cxx_name(const char *sym)
{
    char head[512], *parts[16], *t;
    int np = 0, i, special = 0;
    const char *body = sym + 1, *dd;
    Buf b = { 0, 0, 0 };
    if (*body == '?')
    {
        special = body[1];
        body += 2;
        if (special != '0' && special != '1')
            return NULL;
    }
    dd = strstr(body, "@@");
    if (!dd || (size_t)(dd - body) >= sizeof head)
        return NULL;
    memcpy(head, body, (size_t)(dd - body));
    head[dd - body] = 0;
    for (t = strtok(head, "@"); t && np < 16; t = strtok(NULL, "@"))
        parts[np++] = t;
    if (np == 0)
        return NULL;
    for (i = 0; i < np; i++)
    {
        const char *c;
        if (!is_id0((unsigned char)parts[i][0]))
            return NULL;
        for (c = parts[i]; *c; c++)
            if (!is_id((unsigned char)*c))
                return NULL;
    }
    for (i = np - 1; i >= 0; i--)
    {
        buf_puts(&b, parts[i]);
        buf_puts(&b, "::");
    }
    if (special)
        buf_addf(&b, "%s%s", special == '1' ? "~" : "", parts[0]);
    else
        b.n -= 2, b.p[b.n] = 0;
    return valid_name(b.p) ? b.p : NULL;
}

static char *plain_name(const Row *r)
{
    const char *n = r->name;
    if (n[0] == '?')
        return n[1] == '$' ? NULL : plain_cxx_name(n);
    if (strstr(n, "::") || strchr(n, '<'))
        return valid_name(n) ? xstrdup(n) : NULL;
    if (strchr(n, '$') || strchr(n, '?') || strchr(n, ' '))
        return NULL;
    return plain_c_name(r);
}

/* compiler-made names that say nothing: $E12, _$E3, $$$00001 */
static int artifact_name(const char *n)
{
    if (n[0] == '$')
        return 1;
    if (strncmp(n, "_$E", 3) == 0)
        return 1;
    return 0;
}

/* third-party code that sits among the Microsoft libraries: RAD Game Tools' Bink audio code (_radmalloc,
 * _pushmalloc, _popmalloc, _check_for_MMX) and the Ooura FFT it contains (_bitrv*, _cft*, _makewt, _rdft ...).
 * (_prv*_XDS is not here: the same names are in the WMADEC section, it is Microsoft's WMA decoder.) */
static const char *OOURA[] = {
    "makewt", "makect", "bitrv216", "bitrv216neg", "bitrv208", "bitrv208neg", "cftf1st", "cftb1st", "cftmdl1",
    "cftmdl2", "cftf161", "cftf162", "cftf081", "cftf082", "cftf040", "cftb040", "rftfsub", "rftbsub", "dctsub",
    "cftfx41", "cftexp1", "cftexp2", "cftrec1", "cftrec2", "cftfsub", "cftbsub", "rdft", "ddct", NULL
};
#define OOURA_LO 0x0030AB00u
#define OOURA_HI 0x00310070u

static const char *base_end(const char *s);

static int in_list(const char *name, const char **list)
{
    for (; *list; list++)
        if (strcmp(name, *list) == 0)
            return 1;
    return 0;
}

static int third_party_name(const char *n)
{
    char base[128];
    size_t len = (size_t)(base_end(n) - n);
    const char *b = base;
    static const char *prefix[] = { "rad", "pushmalloc", "popmalloc", "check_for_MMX", NULL };
    const char **p;
    if (len == 0 || len >= sizeof base)
        return 0;
    memcpy(base, n, len);
    base[len] = 0;
    if (b[0] == '_')
        b++;
    if (in_list(b, OOURA))
        return 1;
    for (p = prefix; *p; p++)
        if (strncmp(b, *p, strlen(*p)) == 0)
            return 1;
    return 0;
}

/* Microsoft library names, as the report spells them (C runtime, XAPILIB, C++ run time, undname, XGRAPHICS) */
static int microsoft_name(const char *n)
{
    static const char *cxx_prefix[] = {
        "?Find", "?PMDtoOffset@@", "?_Validate", "?TypeMatch@@", "?BuildCatchObject@@", "?CatchIt@@",
        "?CatchGuardHandler@@", "?_Call", "?_Jump", "?_Unwind", "?_GetRangeOfTrysToCheck", "?__CxxSetUnhandledExceptionFilter",
        "??_L@", "??_M@", "UnDecorator::", "DName::", "DNameNode::", "charNode::", "pcharNode::", "pairNode::",
        "type_info::", "exception::", NULL };
    const char **p;
    const char *c;
    if (artifact_name(n) || third_party_name(n))
        return 0;
    if (strncmp(n, "__ehhandler$", 12) == 0)
        return strstr(n, "@XGRAPHICS@@") != NULL;
    for (p = cxx_prefix; *p; p++)
        if (strncmp(n, *p, strlen(*p)) == 0)
            return 1;
    if (strcmp(n, "operator+") == 0)
        return 1;                                     /* undname's DName operator+ */
    if (n[0] == '?' || strstr(n, "::") || strchr(n, '<') || strchr(n, '$'))
        return 0;
    if (!is_id0((unsigned char)n[0]))
        return 0;
    for (c = n; *c && *c != '@'; c++)
        if (!is_id((unsigned char)*c))
            return 0;
    return 1;
}

static int library_section(const char *s)
{
    return !strcmp(s, "D3D") || !strcmp(s, "D3DX") || !strcmp(s, "XGRPH") || !strcmp(s, "DSOUND") ||
           !strcmp(s, "WMADEC") || !strcmp(s, "XPP");
}

/* ------------------------------------------------------------------------------------ the xbe */

static char *xbe_data;
static size_t xbe_len;

static int xbe_has(const char *s)
{
    size_t n = strlen(s), i;
    if (!xbe_data)
        return 0;
    for (i = 0; i + n <= xbe_len; i++)
        if (xbe_data[i] == s[0] && memcmp(xbe_data + i, s, n) == 0)
            return 1;
    return 0;
}

static int has_zlib, has_png;

/* open-source code whose surrounding code is that library: the family, or NULL */
static const char *open_source_family(const char *plain, unsigned va)
{
    if (va >= 0x002C6000u && va < 0x002CD000u)
    {
        if (has_zlib && (!strncmp(plain, "inflate", 7) || !strncmp(plain, "deflate", 7) || !strcmp(plain, "adler32") ||
                         !strcmp(plain, "crc32") || !strcmp(plain, "zcalloc") || !strcmp(plain, "zcfree") ||
                         !strcmp(plain, "updatewindow") || !strncmp(plain, "_tr_", 4)))
            return "zlib 1.2.1 (the program holds its inflate copyright string)";
        if (has_png && !strncmp(plain, "png_", 4))
            return "libpng (the program holds its version string)";
    }
    if (va >= OOURA_LO && va < OOURA_HI && in_list(plain, OOURA))
        return "Takuya Ooura's FFT package (the whole run of its functions is here, among the Bink audio code)";
    return NULL;
}

/* -------------------------------------------------------------------------------------- bridge */

/* the python that measures starts with the project's own rules; piped into `python -` */
static const char *BRIDGE[] = {
    "import sys, bisect, json\n",
    "sys.path[:] = [p for p in sys.path if p not in ('', '.')]\n",
    "root, candf, listf, outf = sys.argv[1:5]\n",
    "sys.path.insert(0, root + '/portal/tools')\n",
    "import sf_binaries as SB\n",
    "import queue_builder as QB\n",
    "\n",
    "img = SB.BinaryImage(root + '/binaries/default.xbe')\n",
    "calls = SB.collect_call_targets(img)\n",
    "vt = QB.vtable_methods(img)\n",
    "kfs = {int(f['va'], 16): int(f['size']) for f in json.load(open(root + '/reports/known_functions.json'))['functions'] if f.get('bin') == 'xb'}\n",
    "kf = set(kfs)\n",
    "extras = set(json.load(open(root + '/reports/extra_function_starts.json'))['starts']['xb'])\n",
    "extras = {int(v, 16) for v in extras}\n",
    "known = set(calls) | set(vt) | kf\n",
    "listed = {}\n",
    "for line in open(listf):\n",
    "    p = line.split()\n",
    "    if len(p) == 3:\n",
    "        listed[int(p[0], 16)] = (int(p[1]), p[2])\n",
    "cands = {}\n",
    "for line in open(candf):\n",
    "    p = line.split()\n",
    "    if len(p) == 4:\n",
    "        cands[int(p[0], 16)] = (int(p[1]), p[2] == '1', p[3])\n",
    "proven = {v for v, (s, k) in listed.items() if k == 'D'} | kf\n",
    "res = {}\n",
    "meas = {}\n",
    "for c in sorted(cands):\n",
    "    if cands[c][2] == 'E':\n",
    "        e = SB.function_extent(img, c, known)\n",
    "        why = SB.not_compiled_reason(img, c, e.size) if e.ok else (e.reason or 'no extent')\n",
    "        if why:\n",
    "            res[c] = 'REJECT not code by the project rules: ' + why\n",
    "        elif e.size != cands[c][0]:\n",
    "            res[c] = 'REJECT measured %d bytes, report says %d' % (e.size, cands[c][0])\n",
    "        else:\n",
    "            res[c] = 'OK %d' % e.size\n",
    "        continue\n",
    "    sec = img.section_of(c)\n",
    "    if not sec or sec.name != '.text':\n",
    "        res[c] = 'REJECT not in .text'\n",
    "        continue\n",
    "    e = SB.function_extent(img, c, known)\n",
    "    if not e.ok:\n",
    "        res[c] = 'REJECT ' + (e.reason or 'no extent')\n",
    "        continue\n",
    "    why = SB.not_compiled_reason(img, c, e.size)\n",
    "    if why:\n",
    "        res[c] = 'REJECT ' + why\n",
    "        continue\n",
    "    meas[c] = e.size\n",
    "sizes = {v: s for v, (s, k) in listed.items() if k in ('T', 'D')}\n",
    "for c, s in meas.items():\n",
    "    sizes.setdefault(c, s)\n",
    "new, drop = SB.settle_overlaps(img, sizes, set(vt), set(calls), proven)\n",
    "final = {}\n",
    "for c in meas:\n",
    "    if c in drop:\n",
    "        res[c] = 'REJECT false start (settle_overlaps: inside an instruction of the function around it)'\n",
    "    else:\n",
    "        final[c] = new.get(c, meas[c])\n",
    "fstarts = sorted(listed)\n",
    "\n",
    "def end_before(va):\n",
    "    b = img.read(va - 6, 6) or bytes(6)\n",
    "    if b[5] in (0xCC, 0xC3, 0x90):\n",
    "        return 'padding or return'\n",
    "    if b[3] == 0xC2:\n",
    "        return 'ret imm16'\n",
    "    if b[0] == 0xFF and b[1] == 0x25:\n",
    "        return 'tail jump (jmp [mem])'\n",
    "    if b[1] == 0xE9:\n",
    "        return 'tail jump (jmp rel32)'\n",
    "    if b[4] == 0xEB:\n",
    "        return 'tail jump (jmp rel8)'\n",
    "    return ''\n",
    "\n",
    "accepted = []\n",
    "for c in sorted(final):\n",
    "    s = final[c]\n",
    "    want, inferred, _mode = cands[c]\n",
    "    if s != want and not (inferred and 0 < s < want):\n",
    "        res[c] = 'REJECT measured %d bytes, report says %d%s' % (s, want, ' (size inferred)' if inferred else '')\n",
    "        continue\n",
    "    i = bisect.bisect_right(fstarts, c)\n",
    "    if i:\n",
    "        f = fstarts[i - 1]\n",
    "        fs, fk = listed[f]\n",
    "        if f < c < f + fs:\n",
    "            res[c] = 'REJECT inside the %s function at 0x%08X (%d bytes)' % ('verified' if fk == 'D' else 'listed', f, fs)\n",
    "            continue\n",
    "    if i < len(fstarts) and c + s > fstarts[i]:\n",
    "        res[c] = 'REJECT runs over the function at 0x%08X' % fstarts[i]\n",
    "        continue\n",
    "    if accepted and c < accepted[-1][0] + accepted[-1][1]:\n",
    "        res[c] = 'REJECT inside the start at 0x%08X' % accepted[-1][0]\n",
    "        continue\n",
    "    b = end_before(c)\n",
    "    if not b and i:\n",
    "        f = fstarts[i - 1]\n",
    "        gap = c - (f + listed[f][0])\n",
    "        if 0 <= gap <= 15 and all(x in (0xCC, 0x90, 0) for x in (img.read(f + listed[f][0], gap) or b'')):\n",
    "            b = 'follows the function at 0x%08X' % f\n",
    "    if not b:\n",
    "        why = 'REJECT does not follow a return, a tail jump or padding'\n",
    "        for back in range(1, 17):\n",
    "            st = c - back\n",
    "            if end_before(st):\n",
    "                e2 = SB.function_extent(img, st, known)\n",
    "                if e2.ok and st + e2.size == c + s:\n",
    "                    why += '; it is the tail of a %d-byte function at 0x%08X' % (e2.size, st)\n",
    "                    break\n",
    "        res[c] = why\n",
    "        continue\n",
    "    accepted.append((c, s))\n",
    "    res[c] = 'OK %d %s' % (s, b)\n",
    "\n",
    "# the queue build (queue_builder.build_queue) drops a start that lies inside the measured extent of an earlier\n",
    "# one unless it is called or in a vtable: replay its sizing and cover rule over every start\n",
    "lib = {v for v, (s, k) in listed.items() if k == 'L'}\n",
    "done = {v for v, (s, k) in listed.items() if k == 'D'}\n",
    "starts = set(vt) | kf | extras | set(calls) | {c for c, _ in accepted}\n",
    "extents = {}\n",
    "for va in sorted(starts):\n",
    "    sec = img.section_of(va)\n",
    "    if not sec or not sec.is_code or sec.library:\n",
    "        continue\n",
    "    if va in lib and va not in kf and va not in done:\n",
    "        continue\n",
    "    e = SB.function_extent(img, va, known)\n",
    "    if va in kf:\n",
    "        e = SB.Extent(va, kfs[va], True, 'proven')\n",
    "    if e.ok and e.size >= 1 and (va in kf or not SB.not_compiled_reason(img, va, e.size)):\n",
    "        extents[va] = e\n",
    "pv = kf | {va for va in extents if va in done}\n",
    "resized, false_starts = SB.settle_overlaps(img, {va: e.size for va, e in extents.items()}, set(vt), set(calls), pv)\n",
    "for va, n in resized.items():\n",
    "    e = SB.function_extent(img, va, known, max_size=n)\n",
    "    extents[va] = e if e.ok and e.size == n else SB.Extent(va, n, True, 'ends before the next function')\n",
    "for va in false_starts:\n",
    "    del extents[va]\n",
    "cover_end, kept = 0, set()\n",
    "for va in sorted(extents):\n",
    "    if va < cover_end and va not in known:\n",
    "        continue\n",
    "    kept.add(va)\n",
    "    cover_end = max(cover_end, va + extents[va].size)\n",
    "for c, s in accepted:\n",
    "    if c not in kept:\n",
    "        res[c] = 'REJECT the queue build would drop it (inside the measured extent of an earlier start)'\n",
    "with open(outf, 'w') as f:\n",
    "    f.write(chr(10).join('0x%08X %s' % (c, res[c]) for c in sorted(res)) + chr(10))\n",
    NULL
};

static int run_bridge(const char *repo, const char *cand, const char *listed, const char *out)
{
    char cmd[2048];
    FILE *p;
    int i;
    snprintf(cmd, sizeof cmd, "python - \"%s\" \"%s\" \"%s\" \"%s\"", repo, cand, listed, out);
    p = POPEN(cmd, "w");
    if (!p)
        return -1;
    for (i = 0; BRIDGE[i]; i++)
        fputs(BRIDGE[i], p);
    return PCLOSE(p);
}

/* ------------------------------------------------------------------------------------- decisions */

typedef struct { unsigned va; char *name, *by, *why; int in_section; int rowi; } NewName;
static NewName *newnames;
static int nnew, capnew;

typedef struct { unsigned va; int rowi; } Pend;

static const char *ARTIFACT = "compiler-made name";

static int cmp_row_va(const void *a, const void *b)
{
    const Row *x = (const Row *)a, *y = (const Row *)b;
    return x->va < y->va ? -1 : x->va > y->va;
}

static Row *row_find(unsigned va, const char *section_dot_text)
{
    int lo = 0, hi = nrows - 1;
    (void)section_dot_text;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (rows[mid].va < va)
            lo = mid + 1;
        else if (rows[mid].va > va)
            hi = mid - 1;
        else
            return &rows[mid];
    }
    return NULL;
}

typedef struct { const char *why; int n; } Reason;
static Reason reasons[64];
static int nreasons;

static void count_reason(const char *group, const char *why)
{
    int i;
    char key[400];
    snprintf(key, sizeof key, "%s: %s", group, why);
    for (i = 0; i < nreasons; i++)
        if (strcmp(reasons[i].why, key) == 0)
        {
            reasons[i].n++;
            return;
        }
    if (nreasons < 64)
    {
        reasons[nreasons].why = xstrdup(key);
        reasons[nreasons].n = 1;
        nreasons++;
    }
}

static int cmp_reason(const void *a, const void *b)
{
    return strcmp(((const Reason *)a)->why, ((const Reason *)b)->why);
}

static void set_act(Row *r, const char *act, const char *note)
{
    snprintf(r->act, sizeof r->act, "%s", act);
    snprintf(r->note, sizeof r->note, "%s", note ? note : "");
}

static void usage(void)
{
    fprintf(stderr,
            "usage: symcov_import --csv matches.csv [--repo DIR] [--list] [--write | --emit DIR]\n"
            "");
    exit(2);
}

int main(int argc, char **argv)
{
    const char *csv = NULL, *repo = ".", *emit = NULL;
    int list = 0, write = 0;
    char path[1024], path2[1024];
    char *csvbuf;
    size_t len;
    int i, j;
    UL lib_new, lib_sec_new, extra_new;
    char *lib_text, *extra_text, *names_text;
    Span sp_lib, sp_libsec, sp_extra;
    Buf names_add = { 0, 0, 0 }, hints = { 0, 0, 0 };
    int n_names = 0, n_hints = 0;
    int cnt_text = 0;
    int c_done = 0, c_lib = 0, c_todo = 0, c_xtra = 0, c_unl = 0;
    int moved = 0, left_ms_outside = 0, left_third = 0, left_game = 0;
    int added_lib = 0, added_queue = 0, rejected = 0, tail_found = 0;
    int pend = 0;

    for (i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "--csv") && i + 1 < argc)
            csv = argv[++i];
        else if (!strcmp(argv[i], "--repo") && i + 1 < argc)
            repo = argv[++i];
        else if (!strcmp(argv[i], "--emit") && i + 1 < argc)
            emit = argv[++i], write = 1;
        else if (!strcmp(argv[i], "--write"))
            write = 1;
        else if (!strcmp(argv[i], "--list"))
            list = 1;
        else
            usage();
    }
    if (!csv)
        usage();
    memset(&lib_new, 0, sizeof lib_new);
    memset(&lib_sec_new, 0, sizeof lib_sec_new);
    memset(&extra_new, 0, sizeof extra_new);

    /* ---- inputs */
    snprintf(path, sizeof path, "%s/reconstructed_src/Original_Binary_Order_Xbox.cpp", repo);
    load_listing(path);
    snprintf(path, sizeof path, "%s/reports/library_functions.json", repo);
    lib_text = read_file(path, NULL);
    if (!lib_text || !find_array(lib_text, "\"functions\"", "\"xb\"", &sp_lib) ||
        !find_array(lib_text, "\"in_library_sections\"", "\"xb\"", &sp_libsec))
        die("%s: no functions.xb / in_library_sections.xb", path);
    parse_hex_array(lib_text, sp_lib, &lib_list);
    parse_hex_array(lib_text, sp_libsec, &lib_sections);
    snprintf(path, sizeof path, "%s/reports/extra_function_starts.json", repo);
    extra_text = read_file(path, NULL);
    if (!extra_text || !find_array(extra_text, "\"starts\"", "\"xb\"", &sp_extra))
        die("%s: no starts.xb", path);
    parse_hex_array(extra_text, sp_extra, &extra_list);
    snprintf(path, sizeof path, "%s/reports/names.json", repo);
    names_text = read_file(path, NULL);
    if (!names_text)
        die("%s is not there", path);
    load_names(names_text);
    snprintf(path, sizeof path, "%s/binaries/default.xbe", repo);
    xbe_data = read_file(path, &xbe_len);
    has_zlib = xbe_has("inflate 1.2.1 Copyright");
    has_png = xbe_has("libpng version");
    csvbuf = read_file(csv, &len);
    if (!csvbuf)
        die("cannot read %s", csv);
    parse_csv(csvbuf);
    qsort(rows, (size_t)nrows, sizeof(Row), cmp_row_va);

    /* library functions are listed in the address-order file too, with sizes there */
    for (i = 0; i < lib_list.n; i++)
    {
        Fn *f = fn_find(lib_list.v[i]);
        if (f && f->kind == 'T')
            f->kind = 'L';
        else if (!f)
        {
            Row *r = row_find(lib_list.v[i], NULL);
            fn_add(lib_list.v[i], r ? r->size : 0, 'L');
        }
    }
    for (i = 0; i < extra_list.n; i++)
        if (!fn_find(extra_list.v[i]))
        {
            Row *r = row_find(extra_list.v[i], NULL);
            fn_add(extra_list.v[i], r ? r->size : 0, 'X');
        }
    qsort(fns, (size_t)nfns, sizeof(Fn), cmp_fn);

    /* ---- classify the .text rows */
    for (i = 0; i < nrows; i++)
    {
        Row *r = &rows[i];
        if (strcmp(r->section, ".text") != 0)
            continue;
        cnt_text++;
        if (ul_has(&done_list, r->va))
            r->cls = 'D', c_done++;
        else if (ul_has(&lib_list, r->va))
            r->cls = 'L', c_lib++;
        else if (ul_has(&todo_list, r->va))
            r->cls = 'T', c_todo++;
        else if (ul_has(&extra_list, r->va))
            r->cls = 'X', c_xtra++;
        else
            r->cls = 'U', c_unl++;
    }

    /* ---- 2a: measure the unlisted starts with the project's rules */
    {
        FILE *fc, *fl;
        char *res;
        size_t reslen;
        char *line, *next;
        snprintf(path, sizeof path, "%s/build", repo);
        MKDIR(path);
        snprintf(path, sizeof path, "%s/build/symcov_cand.txt", repo);
        fc = fopen(path, "w");
        snprintf(path2, sizeof path2, "%s/build/symcov_listed.txt", repo);
        fl = fopen(path2, "w");
        if (!fc || !fl)
            die("cannot write into %s/build", repo);
        for (i = 0; i < nrows; i++)
        {
            if (rows[i].cls == 'U')
                fprintf(fc, "0x%08X %d %d S\n", rows[i].va, rows[i].size, rows[i].inferred);
            else if (rows[i].cls == 0 && library_section(rows[i].section))
                fprintf(fc, "0x%08X %d %d E\n", rows[i].va, rows[i].size, rows[i].inferred);
        }
        for (i = 0; i < nfns; i++)
            fprintf(fl, "0x%08X %d %c\n", fns[i].va, fns[i].size, fns[i].kind);
        fclose(fc);
        fclose(fl);
        snprintf(path, sizeof path, "%s/build/symcov_cand.txt", repo);
        snprintf(path2, sizeof path2, "%s/build/symcov_listed.txt", repo);
        {
            char out[1024];
            snprintf(out, sizeof out, "%s/build/symcov_measured.txt", repo);
            fprintf(stderr, "measuring %d unlisted starts and the library-section rows with portal/tools/sf_binaries.py ...\n", c_unl);
            if (run_bridge(repo, path, path2, out) != 0)
                die("the python measuring step failed (is capstone installed? python portal/doctor.py says)");
            res = read_file(out, &reslen);
        }
        if (!res)
            die("no result from the measuring step");
        for (line = res; line && *line; line = next)
        {
            unsigned va;
            char *eol = strchr(line, '\n');
            Row *r;
            next = eol ? eol + 1 : NULL;
            if (eol)
                *eol = 0;
            if (sscanf(line, "0x%x", &va) != 1)
                continue;
            r = row_find(va, NULL);
            if (!r)
                continue;
            if (strstr(line, " OK "))
            {
                r->accepted = 1;
                sscanf(strstr(line, " OK ") + 4, "%d", &r->bsize);
            }
            else
            {
                char *why = strstr(line, "REJECT ");
                r->reject = xstrdup(why ? why + 7 : "rejected");
            }
        }
        for (i = 0; i < nrows; i++)
            if (rows[i].cls == 'U' && rows[i].accepted)
                fn_add(rows[i].va, rows[i].bsize, 'N');
        qsort(fns, (size_t)nfns, sizeof(Fn), cmp_fn);
    }

    /* ---- 1/2b: library blocks: unbroken runs of functions that hold at least 8 library functions */
    {
        int *chain = (int *)xmalloc((size_t)nfns * sizeof(int));
        int *nlib = (int *)xmalloc((size_t)(nfns + 1) * sizeof(int));
        unsigned cur_end = 0;
        int cid = -1;
        memset(nlib, 0, (size_t)(nfns + 1) * sizeof(int));
        for (i = 0; i < nfns; i++)
        {
            unsigned size = (unsigned)fns[i].size;
            if (size == 0)
            {
                size = i + 1 < nfns ? fns[i + 1].va - fns[i].va : 16;
                if (size > 0x20)
                    size = 0x20;
            }
            if (cid < 0 || (fns[i].va > cur_end && fns[i].va - cur_end > 0x40))
                cid++, cur_end = 0;
            chain[i] = cid;
            if (fns[i].va + size > cur_end)
                cur_end = fns[i].va + size;
            if (ul_has(&lib_list, fns[i].va))
                nlib[cid]++;
        }
        for (i = 0; i < nrows; i++)
        {
            Fn *f;
            int k;
            if (rows[i].cls == 0)
                continue;
            f = fn_find(rows[i].va);
            if (!f)
                continue;
            k = (int)(f - fns);
            /* fn_find returns the first entry of that address */
            rows[i].in_block = nlib[chain[k]] >= 4;
        }
        free(chain);
        free(nlib);
    }

    /* ---- decisions for .text rows */
    for (i = 0; i < nrows; i++)
    {
        Row *r = &rows[i];
        int ms, third;
        if (r->cls == 0)
            continue;
        if (r->cls == 'L')
            r->in_block = 1;                   /* listed library code is a block by definition */
        ms = microsoft_name(r->name);
        third = third_party_name(r->name);
        if (r->cls == 'D')
        {
            set_act(r, "verified", "");
            continue;
        }
        if (r->cls == 'L')
        {
            set_act(r, "library", "already listed");
            continue;
        }
        if (r->cls == 'U' && !r->accepted)
        {
            char key[200];
            const char *s = r->reject ? r->reject : "?";
            int tailp = strstr(s, "; it is the tail of") != NULL;
            set_act(r, "reject", s);
            rejected++;
            if (tailp)
            {
                tail_found++;
                snprintf(key, sizeof key, "report's start is the tail of a longer function (the real start has another size)");
            }
            else if (strncmp(s, "inside the verified", 19) == 0)
                snprintf(key, sizeof key, "inside a verified function");
            else if (strncmp(s, "inside the listed", 17) == 0)
                snprintf(key, sizeof key, "inside a listed (queued or library) function");
            else if (strncmp(s, "measured", 8) == 0)
                snprintf(key, sizeof key, "measured size differs from the report's");
            else if (strncmp(s, "does not follow", 15) == 0)
                snprintf(key, sizeof key, "does not follow a return, a tail jump or padding");
            else if (strncmp(s, "runs over", 9) == 0)
                snprintf(key, sizeof key, "runs over the next listed start");
            else if (strncmp(s, "the queue build", 15) == 0)
                snprintf(key, sizeof key, "the queue build would drop it (inside the measured extent of an earlier start)");
            else
                snprintf(key, sizeof key, "%s", s);
            count_reason("start rejected", key);
            continue;
        }
        if (ms && !third && r->in_block)
        {
            ul_add(&lib_new, r->va);
            if (r->cls == 'U')
            {
                added_lib++;
                set_act(r, "add-lib", "new start in a library block");
            }
            else
            {
                moved++;
                set_act(r, "to-lib", r->cls == 'T' ? "queued -> library" : "extra start -> library");
            }
            continue;
        }
        /* stays in the queue (or becomes a queued start) */
        if (r->cls == 'U')
        {
            ul_add(&extra_new, r->va);
            added_queue++;
            set_act(r, "add-queue", "new start");
        }
        else
            set_act(r, "queue", "");
        if (third)
        {
            left_third++;
            count_reason("left in the queue", "third-party code among the libraries (RAD Bink audio, Ooura FFT)");
        }
        else if (ms)
        {
            left_ms_outside++;
            count_reason("left in the queue", "Microsoft name, but not in a library block");
        }
        else
        {
            left_game++;
            count_reason("left in the queue", r->in_block ? "inside a library block but not a Microsoft name" : "game code");
        }
    }
    ul_sort(&lib_new);
    ul_sort(&extra_new);

    /* outside .text: a row that starts inside the one before it is not a clean start */
    {
        unsigned end = 0;
        const char *sec = "";
        for (i = 0; i < nrows; i++)
        {
            Row *r = &rows[i];
            if (r->cls != 0)
                continue;
            if (strcmp(sec, r->section) != 0)
                sec = r->section, end = 0;
            if (r->va < end)
                r->overlap = 1;
            if (r->va + (unsigned)r->size > end)
                end = r->va + (unsigned)r->size;
        }
    }

    /* ---- 3: names */
    for (i = 0; i < nrows; i++)
    {
        Row *r = &rows[i];
        char *plain = NULL;
        const char *family = NULL;
        char label[300], by[400];
        int in_section, ok, listed_va, unique;
        Buf why = { 0, 0, 0 };
        if (strncmp(r->section, "BINK", 4) == 0)
            continue;
        in_section = r->cls == 0;
        if (in_section && !library_section(r->section))
            continue;
        if (in_section && !r->accepted)
        {
            count_reason("name skipped", "library-section row is not a function by the project's rules (data table, or code its walk does not size the same)");
            continue;
        }
        if (!in_section && ((r->cls == 'D' && ul_has(&verified_named, r->va)) || (r->cls == 'U' && !r->accepted)))
            continue;
        if (artifact_name(r->name))
            continue;
        unique = strcmp(r->choice, "unique") == 0 && r->ncand == 1;
        plain = plain_name(r);
        if (!in_section)
        {
            ok = microsoft_name(r->name) && r->in_block;
            family = plain ? open_source_family(plain, r->va) : NULL;
            if (!ok && !family)
                continue;                      /* game code etc.: a hint, not a name */
        }
        if (ul_has(&name_vas, r->va))
        {
            count_reason("name skipped", "the address has a name already");
            continue;
        }
        if (!unique)
        {
            count_reason("name skipped", "link-order: identical code under several names, which is which is a guess");
            continue;
        }
        if (!plain)
        {
            count_reason("name skipped", "not an ordinary C++ name (operator, template, compiler-made)");
            continue;
        }
        if (in_section && r->overlap)
        {
            count_reason("name skipped", "starts inside the report's previous function (not a clean start)");
            continue;
        }
        /* an address check_repo.py will know: listed (queue, verified) or in the library lists */
        listed_va = r->cls == 'D' || r->cls == 'L' || r->cls == 'T' || ul_has(&lib_new, r->va) || in_section;
        if (!listed_va)
        {
            count_reason("name waits", "start is new and not yet in the address-order list (run again after registry_outputs.py)");
            r->pending = plain;
            pend++;
            continue;
        }
        if (name_used(plain))
        {
            count_reason("name skipped", "the name is already recorded for another function");
            continue;
        }
        build_label(r, label, sizeof label);
        buf_addf(&why, "The same %d bytes as %s in that build (the symcov report compares code with the addresses masked), and the report names no other function for this code", r->size, r->name);
        if (family)
            buf_addf(&why, "; the code around it is %s", family);
        buf_puts(&why, ".");
        snprintf(by, sizeof by, "symcov: %s", label);
        if (nnew == capnew)
        {
            capnew = capnew ? capnew * 2 : 1024;
            newnames = (NewName *)xrealloc(newnames, (size_t)capnew * sizeof(NewName));
        }
        newnames[nnew].va = r->va;
        newnames[nnew].name = plain;
        newnames[nnew].by = xstrdup(by);
        newnames[nnew].why = why.p;
        newnames[nnew].in_section = in_section && !ul_has(&lib_sections, r->va);
        newnames[nnew].rowi = i;
        r->named = 1;
        nnew++;
    }
    /* a name two functions would get is given to neither (an overloaded name) */
    {
        int k, m, kept = 0;
        for (k = 0; k < nnew; k++)
        {
            int twice = 0;
            for (m = 0; m < nnew; m++)
                if (m != k && strcmp(newnames[m].name, newnames[k].name) == 0)
                    twice = 1;
            if (twice)
            {
                rows[newnames[k].rowi].named = 0;
                count_reason("name skipped", "the same name would go to two functions (given to neither)");
            }
            else
                newnames[kept++] = newnames[k];
        }
        nnew = kept;
        n_names = nnew;
        for (k = 0; k < nnew; k++)
        {
            Row *r = &rows[newnames[k].rowi];
            const char *fam = r->cls == 0 ? r->section : (open_source_family(newnames[k].name, r->va) ? "open-source (zlib, libpng, Ooura FFT)" : ".text Microsoft library code");
            count_reason("names added", fam);
        }
    }
    /* sections: addresses of named non-.text functions that the library list does not have yet */
    for (i = 0; i < nnew; i++)
        if (newnames[i].in_section)
            ul_add(&lib_sec_new, newnames[i].va);
    ul_sort(&lib_sec_new);

    /* ---- 4: hints */
    {
        Buf *h = &hints;
        for (i = 0; i < nrows; i++)
        {
            Row *r = &rows[i];
            const char *kind;
            char label[300];
            if (r->cls == 0 || r->cls == 'D' || r->cls == 'L' || r->named || ul_has(&name_symcov, r->va))
                continue;
            if (r->cls == 'U' && !r->accepted)
                continue;
            if (!strcmp(r->act, "to-lib") || !strcmp(r->act, "add-lib"))
                continue;
            if (artifact_name(r->name) || strncmp(r->name, "__ehhandler$", 12) == 0)
            {
                count_reason("hint skipped", "compiler-made name (static initialiser, exception handler stub): says nothing");
                continue;
            }
            if (third_party_name(r->name))
                kind = "third-party";
            else
                kind = "game";
            build_label(r, label, sizeof label);
            buf_addf(h, "%s\n    \"xb:0x%08X\": {\n      \"hint\": \"", n_hints ? "," : "", r->va);
            buf_json(h, r->name);
            buf_puts(h, "\",\n      \"build\": \"");
            buf_json(h, label);
            buf_addf(h, "\",\n      \"choice\": \"%s\",\n      \"candidates\": %d,\n      \"size\": %d,\n      \"kind\": \"%s\"",
                     r->choice, r->ncand, r->size, kind);
            if (r->pending)
            {
                buf_puts(h, ",\n      \"name_pending\": \"");
                buf_json(h, r->pending);
                buf_puts(h, "\"");
            }
            buf_puts(h, "\n    }");
            n_hints++;
            count_reason("hints", kind);
        }
    }

    /* ---- the report */
    if (list)
    {
        for (i = 0; i < nrows; i++)
        {
            Row *r = &rows[i];
            if (r->cls == 0)
                continue;
            printf("0x%08X %c %-9s blk=%d %-34.34s %s\n", r->va, r->cls, r->act, r->in_block, r->name, r->note);
        }
    }
    qsort(reasons, (size_t)nreasons, sizeof(Reason), cmp_reason);
    printf("rows: %d (%d in .text)\n", nrows, cnt_text);
    printf(".text rows by what the project has: %d verified, %d library-listed, %d queued, %d extra starts not in the list, %d unlisted\n",
           c_done, c_lib, c_todo, c_xtra, c_unl);
    printf("1. library reclassification: %d queued/extra functions -> library list; left in the queue: %d game code, %d third-party, %d Microsoft names outside a library block\n",
           moved, left_game, left_third, left_ms_outside);
    printf("2. unlisted starts: %d accepted (%d to the library list, %d to the queue), %d rejected (%d of them are the tail of a longer function)\n",
           added_lib + added_queue, added_lib, added_queue, rejected, tail_found);
    printf("3. names: %d added (%d waiting for a start that is not listed yet); %d library-section addresses added to in_library_sections\n",
           n_names, pend, lib_sec_new.n);
    printf("4. hints: %d\n", n_hints);
    for (i = 0; i < nreasons; i++)
        printf("   %s: %d\n", reasons[i].why, reasons[i].n);

    /* ---- write */
    if (write)
    {
        const char *root = emit ? emit : repo;
        UL all;
        char *out;
        size_t outlen;

        /* library_functions.json */
        memset(&all, 0, sizeof all);
        for (i = 0; i < lib_list.n; i++)
            ul_add(&all, lib_list.v[i]);
        for (i = 0; i < lib_new.n; i++)
            ul_add(&all, lib_new.v[i]);
        ul_sort(&all);
        {
            /* rewrite functions.xb first, then re-find in_library_sections in the new text */
            Span sp;
            char *t1 = rewrite_array(lib_text, sp_lib, &all, &outlen);
            UL all2;
            memset(&all2, 0, sizeof all2);
            for (i = 0; i < lib_sections.n; i++)
                ul_add(&all2, lib_sections.v[i]);
            for (i = 0; i < lib_sec_new.n; i++)
                ul_add(&all2, lib_sec_new.v[i]);
            ul_sort(&all2);
            if (!find_array(t1, "\"in_library_sections\"", "\"xb\"", &sp))
                die("lost in_library_sections");
            out = rewrite_array(t1, sp, &all2, &outlen);
            snprintf(path, sizeof path, "%s/reports/library_functions.json", root);
            write_file(path, out, outlen);
        }
        /* extra_function_starts.json */
        memset(&all, 0, sizeof all);
        for (i = 0; i < extra_list.n; i++)
            ul_add(&all, extra_list.v[i]);
        for (i = 0; i < extra_new.n; i++)
            ul_add(&all, extra_new.v[i]);
        ul_sort(&all);
        out = rewrite_array(extra_text, sp_extra, &all, &outlen);
        snprintf(path, sizeof path, "%s/reports/extra_function_starts.json", root);
        write_file(path, out, outlen);
        /* names.json: entries are added at the end of "names" */
        if (nnew)
        {
            const char *nm = strstr(names_text, "\"names\": {");
            const char *q;
            int depth = 0, instr = 0;
            Buf nb = { 0, 0, 0 };
            size_t at;
            if (!nm)
                die("names.json has no names object");
            for (q = strchr(nm, '{'); *q; q++)
            {
                if (instr)
                {
                    if (*q == '\\')
                        q++;
                    else if (*q == '"')
                        instr = 0;
                    continue;
                }
                if (*q == '"')
                    instr = 1;
                else if (*q == '{')
                    depth++;
                else if (*q == '}' && --depth == 0)
                    break;
            }
            at = (size_t)(q - names_text);
            while (at > 0 && isspace((unsigned char)names_text[at - 1]))
                at--;
            buf_add(&nb, names_text, at);
            for (i = 0; i < nnew; i++)
            {
                buf_addf(&nb, ",\n    \"xb:0x%08X\": {\n      \"name\": \"", newnames[i].va);
                buf_json(&nb, newnames[i].name);
                buf_puts(&nb, "\",\n      \"by\": \"");
                buf_json(&nb, newnames[i].by);
                buf_puts(&nb, "\",\n      \"why\": \"");
                buf_json(&nb, newnames[i].why);
                buf_puts(&nb, "\"\n    }");
            }
            buf_puts(&nb, names_text + at);
            snprintf(path, sizeof path, "%s/reports/names.json", root);
            write_file(path, nb.p, nb.n);
        }
        /* symcov_hints.json */
        {
            Buf hb = { 0, 0, 0 };
            buf_puts(&hb,
                     "{\n  \"schema\": \"scarface_symcov_hints_v1\",\n"
                     "  \"note\": \"For functions of game code that a symcov report of default.xbe found identical to a named function in "
                     "another game's build. The name is what that other game called the code: a hint to what it does, never this "
                     "game's name for it (AGENTS.md ruling 2). Keys: xb:address. choice: unique (one name for this code) or "
                     "link-order (the same code has several names and the report assigned this one by link order, so it is a guess "
                     "within them). kind: game, or third-party (RAD Game Tools' Bink audio code and the Ooura FFT it holds, "
                     "found among the Microsoft libraries). Made by tools/symcov_import.c.\",\n"
                     "  \"hints\": {");
            buf_add(&hb, hints.p ? hints.p : "", hints.n);
            buf_puts(&hb, n_hints ? "\n  }\n}\n" : "}\n}\n");
            snprintf(path, sizeof path, "%s/reports/symcov_hints.json", root);
            write_file(path, hb.p, hb.n);
        }
        printf("written under %s/reports: library_functions.json, extra_function_starts.json, names.json, symcov_hints.json\n", root);
        if (!emit)
            printf("next: python portal/tools/registry_outputs.py (regenerates reconstructed_src/ and reports/progress.json), then run this tool again\n");
    }
    (void)ARTIFACT;
    (void)j;
    return 0;
}
