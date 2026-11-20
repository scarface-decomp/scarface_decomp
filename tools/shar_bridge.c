/*
 * shar_bridge: names for Scarface's Xbox functions from The Simpsons: Hit & Run's PS2 linker map, carried
 * through Hit & Run's retail Xbox build.
 *
 *   build\shar_bridge                 (dry run: the measurements and what would be written)
 *   build\shar_bridge --list          (also every candidate, every disagreement and every hint)
 *   build\shar_bridge --write         (add the names to reports/names.json, rewrite reports/shar_bridge_hints.json)
 *   options: --repo DIR  --map SRR2.MAP  --elf SLUS_206.24  --shar default.xbe (Hit & Run's Xbox build)
 *            --refresh (measure both Xbox programs again instead of reusing build/shar_bridge/)
 *
 * The inputs (the owner's own copies, never put in the repository; docs/NAMES.md, AGENTS.md rulings 1, 2, 4):
 * the 10 July 2003 PS2 prototype of Hit & Run (SLUS_206.24 and its linker map SRR2.MAP, g++ 2.9x names), the
 * retail Xbox build of Hit & Run (default.xbe, 24 July 2003, Visual C++, class information but no symbols),
 * and binaries/default.xbe. Only the programs and the map are read; nothing of either game's source code.
 *
 * Why a bridge. The PS2 build and Scarface come from different compilers, so their code never matches. The two
 * Hit & Run builds are the same source two weeks apart; the two Xbox programs come from the same compiler family.
 *
 * Hop 1, PS2 symbol -> Hit & Run Xbox function. Signals (each independent of the others):
 *   V  slot of a table of virtual functions: the PS2 table _vt$<class> and the Xbox class information's table of
 *      the class with the same name have the same number of slots, and every table the PS2 function sits in puts
 *      the same Xbox function there;
 *   S  a string used by exactly one function on each side (PS2: lui/addiu pairs; Xbox: operands);
 *   R  the parameter list in the g++ symbol of a member function adds up to the bytes the Xbox function's `ret N`
 *      removes, and that is more than 0 (a mismatch that is not explained by a returned object, +4, vetoes);
 *   G  the call graph: an anchor pair (two signals) whose call lists have the same length and the same pattern
 *      of repeats pairs its callees in order, when no pair is vetoed by R.
 *   Only PS2 symbols from the game's own objects and Radical's libraries (not the PS2 SDK, libgcc, libstdc++,
 *   libm, zlib, libpng); the pairing must be one to one.
 * Hop 2, Hit & Run Xbox function -> Scarface function. Signals:
 *   I  identical code with the addresses masked, found once in each program (the strongest);
 *   T  slot of a table of virtual functions of the same class under the engine's renaming (tCamera ->
 *      pure3d::Camera, pddiShader -> pure3d::pddiShader, radDrive -> core::Drive, IRadDrive -> core::IDrive,
 *      Scrooby::Page -> pure3d::frontend::Page, RadicalMathLibrary::Vector -> math::Vector where
 *      Scarface's class information names math::Vector, otherwise the one Scarface class with the same last name part):
 *      same number of slots, or the same number of own slots after a base class both have;
 *   S  a string, K a constant (a float read from memory, or an unusual 32-bit immediate), each used by exactly
 *      one function in each program;
 *   R  both functions remove the same number of bytes (ret N, N > 0); different numbers veto;
 *   G  the call graph, as on hop 1, from pairs with I or two signals.
 *   The pairing must be one to one.
 * Both Xbox functions must be 24 bytes or more: the linkers fold identical small functions (one Xbox function
 * then serves many PS2 functions, measured), so a small function's name is never certain.
 *
 * Written to reports/names.json: hop 1 with two signals AND hop 2 with I, or T together with R (hop 2's S, K and G
 * never met a recorded name they agreed with, so they only make hints), the Scarface function
 * without a name in names.json, the name not taken, and where the class information files the function under a
 * class (Class::vfunc_NN), that class agrees (the same class, a base, a derived class, or the same last name
 * part). Written to reports/shar_bridge_hints.json: the other one-to-one chains with at least one signal on
 * each hop that nothing contradicts; a hint is never a name. A function whose existing name disagrees is only
 * listed (--list) and counted.
 *
 * Not C: the two Xbox programs are measured (function starts and sizes, `ret N`, call targets, masked-code
 * hashes, strings, constants, tables of virtual functions) by the project's own python modules
 * (portal/tools/sf_binaries.py with capstone, portal/scripts/names_from_messages.py for the class information):
 * the tool pipes the python below (BRIDGE) into `python -` and keeps the results in build/shar_bridge/. The PS2
 * program (MIPS) and the map are read here, in C.
 *
 * What it does not check: that a function kept its meaning between 2003 and 2006 (a name is a label from 2003);
 * the order of overloads (an overloaded name would name two functions and is not written); calls through
 * pointers; functions that the 2006 build inlined or merged.
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
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif

#define BY "the Hit & Run prototype's linker map, through the retail Xbox build"
#define MIN_SIZE 24

/* ------------------------------------------------------------------------------------------ util */

static void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "shar_bridge: ");
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

static void buf_puts(Buf *b, const char *s) { buf_add(b, s, strlen(s)); }

static void buf_addf(Buf *b, const char *fmt, ...)
{
    char tmp[8192];
    va_list ap;
    int n;
    va_start(ap, fmt);
    n = vsnprintf(tmp, sizeof tmp, fmt, ap);
    va_end(ap);
    if (n < 0 || n >= (int)sizeof tmp)
        n = (int)sizeof tmp - 1;
    buf_add(b, tmp, (size_t)n);
}

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

static unsigned hexval(const char *s, const char **end)
{
    unsigned v = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        s += 2;
    while (isxdigit((unsigned char)*s))
    {
        v = v * 16 + (unsigned)(isdigit((unsigned char)*s) ? *s - '0' : (tolower((unsigned char)*s) - 'a' + 10));
        s++;
    }
    if (end)
        *end = s;
    return v;
}

static u64 hex64(const char *s)
{
    u64 v = 0;
    while (isxdigit((unsigned char)*s))
    {
        v = v * 16 + (u64)(isdigit((unsigned char)*s) ? *s - '0' : (tolower((unsigned char)*s) - 'a' + 10));
        s++;
    }
    return v;
}

static u64 fnv(const unsigned char *p, size_t n)
{
    u64 h = 0xcbf29ce4;
    size_t i;
    h = (h << 32) | 0x84222325;
    for (i = 0; i < n; i++)
    {
        h ^= p[i];
        h *= ((u64)0x100 << 32) | 0x1b3;
    }
    return h;
}

/* sorted arrays of unsigned and of u64 */
typedef struct { unsigned *v; int n, cap; } UL;
typedef struct { u64 *v; int n, cap; } QL;

static void ul_add(UL *l, unsigned x)
{
    if (l->n == l->cap)
    {
        l->cap = l->cap * 2 + 16;
        l->v = (unsigned *)xrealloc(l->v, l->cap * sizeof *l->v);
    }
    l->v[l->n++] = x;
}

static void ql_add(QL *l, u64 x)
{
    if (l->n == l->cap)
    {
        l->cap = l->cap * 2 + 8;
        l->v = (u64 *)xrealloc(l->v, l->cap * sizeof *l->v);
    }
    l->v[l->n++] = x;
}

static int cmp_u(const void *a, const void *b)
{
    unsigned x = *(const unsigned *)a, y = *(const unsigned *)b;
    return x < y ? -1 : x > y;
}

static int cmp_q(const void *a, const void *b)
{
    u64 x = *(const u64 *)a, y = *(const u64 *)b;
    return x < y ? -1 : x > y;
}

static void ul_sort(UL *l)
{
    int i, j = 0;
    if (!l->n)
        return;
    qsort(l->v, l->n, sizeof *l->v, cmp_u);
    for (i = 1; i < l->n; i++)
        if (l->v[i] != l->v[j])
            l->v[++j] = l->v[i];
    l->n = j + 1;
}

static void ql_sort(QL *l)
{
    int i, j = 0;
    if (!l->n)
        return;
    qsort(l->v, l->n, sizeof *l->v, cmp_q);
    for (i = 1; i < l->n; i++)
        if (l->v[i] != l->v[j])
            l->v[++j] = l->v[i];
    l->n = j + 1;
}

static int ul_has(const UL *l, unsigned x)
{
    return l->n && bsearch(&x, l->v, l->n, sizeof x, cmp_u) != NULL;
}

/* ------------------------------------------------------------------------- the Xbox measurements */

typedef struct
{
    unsigned va;
    int size;
    int lib;            /* in a library section (D3D, DSOUND, BINK...) */
    int nret, ret;      /* distinct ret values; ret: the value when there is one */
    u64 hash;           /* the code with addresses masked */
    UL calls;           /* direct call targets, in order, repeats kept */
    QL strs, consts;    /* sorted */
} XF;

typedef struct { XF *f; int n; } Prog;

typedef struct { char *name; char **bases; int nb; unsigned *fns; int nf; } Cls;
typedef struct { Cls *c; int n; } Classes;

static XF *xf_find(const Prog *p, unsigned va)
{
    int lo = 0, hi = p->n - 1;
    while (lo <= hi)
    {
        int m = (lo + hi) / 2;
        if (p->f[m].va == va)
            return &p->f[m];
        if (p->f[m].va < va)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return NULL;
}

static char *next_field(char **pp)
{
    char *s = *pp, *e;
    while (*s == ' ')
        s++;
    e = s;
    while (*e && *e != ' ' && *e != '\n' && *e != '\r')
        e++;
    if (*e)
        *e++ = 0;
    *pp = e;
    return s;
}

static void load_prog(const char *path, Prog *p)
{
    char *text = read_file(path, NULL), *line, *nl;
    int cap = 0;
    if (!text)
        die("cannot read %s", path);
    p->n = 0;
    p->f = NULL;
    for (line = text; *line; line = nl)
    {
        char *q, *t;
        XF f;
        nl = strchr(line, '\n');
        nl = nl ? (*nl = 0, nl + 1) : line + strlen(line);
        if (strlen(line) < 10)
            continue;
        memset(&f, 0, sizeof f);
        q = line;
        f.va = hexval(next_field(&q), NULL);
        f.size = atoi(next_field(&q));
        t = next_field(&q);
        f.lib = strcmp(t, ".text") != 0;
        t = next_field(&q);
        if (*t != '-')
        {
            const char *e = t;
            f.nret = 0;
            while (*e)
            {
                f.ret = (int)hexval(e, &e);
                f.nret++;
                if (*e == ',')
                    e++;
            }
        }
        f.hash = hex64(next_field(&q));
        next_field(&q);                                 /* the call count */
        t = next_field(&q);
        if (*t != '-')
        {
            const char *e = t;
            while (*e)
            {
                ul_add(&f.calls, hexval(e, &e));
                if (*e == ',')
                    e++;
            }
        }
        t = next_field(&q);
        if (*t != '-')
        {
            char *e = t;
            while (*e)
            {
                ql_add(&f.strs, hex64(e));
                while (*e && *e != ',')
                    e++;
                if (*e)
                    e++;
            }
        }
        t = next_field(&q);
        if (*t != '-')
        {
            char *e = t;
            while (*e)
            {
                char *s = e;
                while (*e && *e != ',')
                    e++;
                ql_add(&f.consts, fnv((const unsigned char *)s, (size_t)(e - s)));
                if (*e)
                    e++;
            }
        }
        ql_sort(&f.strs);
        ql_sort(&f.consts);
        if (p->n == cap)
        {
            cap = cap * 2 + 1024;
            p->f = (XF *)xrealloc(p->f, cap * sizeof *p->f);
        }
        p->f[p->n++] = f;
    }
    free(text);
}

static int cmp_cls(const void *a, const void *b)
{
    return strcmp(((const Cls *)a)->name, ((const Cls *)b)->name);
}

static void load_classes(const char *path, Classes *cs)
{
    char *text = read_file(path, NULL), *line, *nl;
    int cap = 0;
    if (!text)
        die("cannot read %s", path);
    cs->n = 0;
    cs->c = NULL;
    for (line = text; *line; line = nl)
    {
        char *b1, *b2, *e;
        Cls c;
        nl = strchr(line, '\n');
        nl = nl ? (*nl = 0, nl + 1) : line + strlen(line);
        b1 = strchr(line, '|');
        if (!b1)
            continue;
        b2 = strchr(b1 + 1, '|');
        if (!b2)
            continue;
        *b1 = *b2 = 0;
        memset(&c, 0, sizeof c);
        c.name = xstrdup(line);
        for (e = b1 + 1; *e;)
        {
            char *s = e;
            while (*e && *e != ',')
                e++;
            c.bases = (char **)xrealloc(c.bases, (c.nb + 1) * sizeof *c.bases);
            c.bases[c.nb] = (char *)xmalloc((size_t)(e - s) + 1);
            memcpy(c.bases[c.nb], s, (size_t)(e - s));
            c.bases[c.nb++][e - s] = 0;
            if (*e)
                e++;
        }
        for (e = b2 + 1; *e;)
        {
            const char *x;
            c.fns = (unsigned *)xrealloc(c.fns, (c.nf + 1) * sizeof *c.fns);
            c.fns[c.nf++] = hexval(e, &x);
            e = (char *)x;
            if (*e == ',')
                e++;
            else
                break;
        }
        if (cs->n == cap)
        {
            cap = cap * 2 + 256;
            cs->c = (Cls *)xrealloc(cs->c, cap * sizeof *cs->c);
        }
        cs->c[cs->n++] = c;
    }
    qsort(cs->c, cs->n, sizeof *cs->c, cmp_cls);
    free(text);
}

static Cls *cls_find(const Classes *cs, const char *name)
{
    Cls key;
    key.name = (char *)name;
    return name ? (Cls *)bsearch(&key, cs->c, cs->n, sizeof key, cmp_cls) : NULL;
}

static int cls_has_base(const Cls *c, const char *base)
{
    int i;
    for (i = 0; c && base && i < c->nb; i++)
        if (strcmp(c->bases[i], base) == 0)
            return 1;
    return 0;
}

/* ------------------------------------------------------------------------------------- the bridge */

/* the python that measures one Xbox program; piped into `python -` (root, which, xbe, out) */
static const char *BRIDGE[] = {
    "import sys, struct, hashlib\n",
    "sys.path[:] = [p for p in sys.path if p not in ('', '.')]\n",
    "root, which, xbe, outf = sys.argv[1:5]\n",
    "sys.path.insert(0, root + '/portal/tools')\n",
    "sys.path.insert(0, root + '/portal/scripts')\n",
    "import sf_binaries as SB\n",
    "import names_from_messages as NM\n",
    "import capstone\n",
    "from capstone import x86_const as X\n",
    "img = SB.BinaryImage(xbe)\n",
    "base = img.image_base\n",
    "hi = max(s.va + max(s.vsize, s.raw_size) for s in img.sections)\n",
    "code = img.code_sections()\n",
    "data = [s for s in img.sections if not s.is_code and s.raw_size]\n",
    "def in_code(v):\n",
    "    return any(c.va <= v < c.va + c.raw_size for c in code)\n",
    "bases, tables = NM.hierarchy(img)\n",
    "vt_entries = set()\n",
    "for fns in tables.values():\n",
    "    vt_entries.update(fns)\n",
    "calls = SB.collect_call_targets(img)\n",
    "if which == 'sf':\n",
    "    import registry_outputs as RO\n",
    "    from pathlib import Path\n",
    "    known = RO.known_from_files(Path(root) / 'reconstructed_src').get('xb', {})\n",
    "    funcs = {va: t['size'] for va, t in known.items()}\n",
    "else:\n",
    "    starts = set(calls) | vt_entries\n",
    "    for s in data:\n",
    "        blob = img.data[s.raw:s.raw + s.raw_size]\n",
    "        for o in range(0, len(blob) - 3, 4):\n",
    "            p = struct.unpack_from('<I', blob, o)[0]\n",
    "            if p in starts or not in_code(p):\n",
    "                continue\n",
    "            b = img.read(p - 1, 1)\n",
    "            if b and b[0] in (0xCC, 0xC3, 0x90):\n",
    "                starts.add(p)\n",
    "    funcs = {}\n",
    "    known = set(starts)\n",
    "    pending = sorted(starts)\n",
    "    while pending:\n",
    "        nxt = []\n",
    "        for va in pending:\n",
    "            if va in funcs:\n",
    "                continue\n",
    "            e = SB.function_extent(img, va, known)\n",
    "            if not e.ok or SB.not_compiled_reason(img, va, e.size):\n",
    "                continue\n",
    "            funcs[va] = e.size\n",
    "            q = va + e.size\n",
    "            sec = img.section_of(va)\n",
    "            while q < sec.va + sec.raw_size and img.read(q, 1)[0] in (0xCC, 0x90):\n",
    "                q += 1\n",
    "            if q < sec.va + sec.raw_size and q not in known and q not in funcs:\n",
    "                known.add(q)\n",
    "                nxt.append(q)\n",
    "        pending = sorted(set(nxt))\n",
    "    sizes, drop = SB.settle_overlaps(img, dict(funcs), vt_entries, set(calls), set())\n",
    "    for va in drop:\n",
    "        funcs.pop(va, None)\n",
    "    for va, n in sizes.items():\n",
    "        if va in funcs:\n",
    "            funcs[va] = n\n",
    "    cover = 0\n",
    "    for va in sorted(funcs):\n",
    "        if va < cover and va not in calls and va not in vt_entries:\n",
    "            del funcs[va]\n",
    "            continue\n",
    "        cover = max(cover, va + funcs[va])\n",
    "md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)\n",
    "md.detail = True\n",
    "def cstring(va):\n",
    "    s = img.section_of(va)\n",
    "    if not s or s.is_code:\n",
    "        return None\n",
    "    b = img.read(va, 256) or img.read(va, 16)\n",
    "    if not b:\n",
    "        return None\n",
    "    end = b.find(bytes(1))\n",
    "    if end < 4:\n",
    "        return None\n",
    "    t = b[:end]\n",
    "    if all(32 <= c < 127 or c in (9, 10, 13) for c in t):\n",
    "        return t\n",
    "    return None\n",
    "def tok(b):\n",
    "    h = 0xcbf29ce484222325\n",
    "    for c in b:\n",
    "        h = ((h ^ c) * 0x100000001b3) & 0xFFFFFFFFFFFFFFFF\n",
    "    return '%016x' % h\n",
    "out = []\n",
    "for va in sorted(funcs):\n",
    "    size = funcs[va]\n",
    "    sec = img.section_of(va)\n",
    "    blob = img.read(va, size) or b''\n",
    "    mask = bytearray(blob)\n",
    "    rets, callees, strs, consts = [], [], [], []\n",
    "    for insn in md.disasm(blob, va):\n",
    "        off = insn.address - va\n",
    "        mn = insn.mnemonic\n",
    "        if mn == 'ret':\n",
    "            rets.append(insn.operands[0].imm if insn.operands else 0)\n",
    "        for op in insn.operands:\n",
    "            if op.type == X.X86_OP_IMM:\n",
    "                v = op.imm & 0xFFFFFFFF\n",
    "                if insn.group(capstone.CS_GRP_JUMP) or insn.group(capstone.CS_GRP_CALL):\n",
    "                    if mn == 'call' and in_code(v):\n",
    "                        callees.append(v)\n",
    "                    if not (va <= v < va + size) and insn.imm_size == 4:\n",
    "                        mask[off + insn.imm_offset:off + insn.imm_offset + 4] = bytes(4)\n",
    "                    continue\n",
    "                if base <= v < hi:\n",
    "                    if insn.imm_size == 4:\n",
    "                        mask[off + insn.imm_offset:off + insn.imm_offset + 4] = bytes(4)\n",
    "                    t = cstring(v)\n",
    "                    if t:\n",
    "                        strs.append(tok(t))\n",
    "                elif insn.imm_size == 4 and 0x10000 < v < 0xFFFF0000:\n",
    "                    consts.append('i%08x' % v)\n",
    "            elif op.type == X.X86_OP_MEM:\n",
    "                d = op.mem.disp & 0xFFFFFFFF\n",
    "                if base <= d < hi and insn.disp_size == 4:\n",
    "                    mask[off + insn.disp_offset:off + insn.disp_offset + 4] = bytes(4)\n",
    "                    t = cstring(d)\n",
    "                    if t:\n",
    "                        strs.append(tok(t))\n",
    "                    if op.mem.base == 0 and op.mem.index == 0 and (mn.startswith('f') or 'ss' in mn or 'sd' in mn):\n",
    "                        raw = img.read(d, op.size)\n",
    "                        if raw and op.size in (4, 8):\n",
    "                            consts.append('f' + raw.hex())\n",
    "    out.append('%08x %d %s %s %s %d %s %s %s' % (\n",
    "        va, size, sec.name,\n",
    "        ','.join('%x' % r for r in sorted(set(rets))) or '-',\n",
    "        hashlib.blake2b(bytes(mask), digest_size=8).hexdigest(), len(callees),\n",
    "        ','.join('%08x' % c for c in callees) or '-',\n",
    "        ','.join(sorted(set(strs))) or '-',\n",
    "        ','.join(sorted(set(consts))) or '-'))\n",
    "with open(outf + '.tmp', 'w') as f:\n",
    "    f.write(chr(10).join(out) + chr(10))\n",
    "with open(outf + '.vt', 'w') as f:\n",
    "    for cls in sorted(tables):\n",
    "        f.write('%s|%s|%s' % (cls, ','.join(bases.get(cls, [])), ','.join('%08x' % v for v in tables[cls])) + chr(10))\n",
    "import os\n",
    "os.replace(outf + '.tmp', outf)\n",
    NULL
};

static void run_bridge(const char *repo, const char *which, const char *xbe, const char *out)
{
    char cmd[2048];
    FILE *p;
    int i;
    snprintf(cmd, sizeof cmd, "python - \"%s\" %s \"%s\" \"%s\"", repo, which, xbe, out);
    p = POPEN(cmd, "w");
    if (!p)
        die("cannot run python");
    for (i = 0; BRIDGE[i]; i++)
        fputs(BRIDGE[i], p);
    if (PCLOSE(p) != 0)
        die("the python measuring step failed for %s (is capstone installed? python portal/doctor.py says)", xbe);
}

/* --------------------------------------------------------------------------------- the PS2 side */

typedef struct
{
    unsigned va;
    int size;
    char *sym;
    int usable;         /* from the game's objects or Radical's libraries */
    char cls[160];      /* demangled class, "" for none */
    char meth[128];     /* the function's own name, "" when it has none to give */
    char kind;          /* m member, s static, f free, C a C function, c ctor, d dtor, o other */
    int pbytes;         /* stack bytes of the parameters, -1 unknown */
    UL jals;
    QL strs;
} PF;

static PF *pf;
static int npf;

typedef struct { char *cls; unsigned *fns; int nf; } PTab;
static PTab *ptab;
static int nptab;

static PF *pf_find(unsigned va)
{
    int lo = 0, hi = npf - 1;
    while (lo <= hi)
    {
        int m = (lo + hi) / 2;
        if (pf[m].va == va)
            return &pf[m];
        if (pf[m].va < va)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return NULL;
}

static int cmp_pf(const void *a, const void *b)
{
    unsigned x = ((const PF *)a)->va, y = ((const PF *)b)->va;
    return x < y ? -1 : x > y;
}

/* one class name of the old GNU scheme at s (7tCamera, Q27Scrooby4Page, Q_12_...); returns the end or NULL */
static const char *read_name(const char *s, char *out, size_t cap)
{
    int count = 1, k;
    out[0] = 0;
    if (*s == 'Q')
    {
        if (s[1] == '_')
        {
            count = atoi(s + 2);
            s = strchr(s + 2, '_');
            if (!s)
                return NULL;
            s++;
        }
        else if (isdigit((unsigned char)s[1]))
        {
            count = s[1] - '0';
            s += 2;
        }
        else
            return NULL;
    }
    for (k = 0; k < count; k++)
    {
        int n = 0, i;
        if (!isdigit((unsigned char)*s))
            return NULL;
        while (isdigit((unsigned char)*s))
            n = n * 10 + (*s++ - '0');
        if ((int)strlen(s) < n || n == 0 || !(isalpha((unsigned char)s[0]) || s[0] == '_'))
            return NULL;
        for (i = 0; i < n; i++)
            if (!(isalnum((unsigned char)s[i]) || s[i] == '_'))
                return NULL;
        if (strlen(out) + n + 3 >= cap)
            return NULL;
        if (k)
            strcat(out, "::");
        strncat(out, s, n);
        s += n;
    }
    return s;
}

static const char *skip_type(const char *s)
{
    char tmp[256];
    while (*s && strchr("CVUSPR", *s))
        s++;
    if (!*s)
        return NULL;
    if (strchr("ilfcsbwhdxvr", *s))
        return s + 1;
    if (isdigit((unsigned char)*s) || *s == 'Q')
        return read_name(s, tmp, sizeof tmp);
    if (*s == 'F')
    {
        const char *u = strchr(s, '_');
        return u ? skip_type(u + 1) : NULL;
    }
    return NULL;
}

/* the stack bytes of a g++ 2.9x parameter list, or -1 when one parameter's size is not known */
static int param_bytes(const char *s)
{
    int sz[64], n = 0, total = 0, i;
    while (*s)
    {
        char c;
        while (*s && strchr("CVUS", *s))
            s++;
        c = *s;
        if (!c || n >= 60)
            return -1;
        if (c == 'P' || c == 'R')
        {
            s = skip_type(s + 1);
            if (!s)
                return -1;
            sz[n++] = 4;
        }
        else if (strchr("ilfcsbwh", c))
        {
            sz[n++] = 4;
            s++;
        }
        else if (c == 'd' || c == 'x')
        {
            sz[n++] = 8;
            s++;
        }
        else if (c == 'v')
            s++;
        else if (c == 'T' && isdigit((unsigned char)s[1]))
        {
            int k = s[1] - '0' - 1;
            if (k < 0 || k >= n)
                return -1;
            sz[n] = sz[k];
            n++;
            s += 2;
        }
        else if (c == 'N' && isdigit((unsigned char)s[1]) && isdigit((unsigned char)s[2]))
        {
            int cnt = s[1] - '0', k = s[2] - '0' - 1, j;
            if (k < 0 || k >= n || n + cnt >= 60)
                return -1;
            for (j = 0; j < cnt; j++, n++)
                sz[n] = sz[k];
            s += 3;
        }
        else
            return -1;                                  /* a class by value, an ellipsis, a template... */
    }
    for (i = 0; i < n; i++)
        total += sz[i];
    return total;
}

static int is_ident(const char *s)
{
    if (!(isalpha((unsigned char)*s) || *s == '_'))
        return 0;
    for (; *s; s++)
        if (!(isalnum((unsigned char)*s) || *s == '_'))
            return 0;
    return 1;
}

static void demangle(PF *f)
{
    const char *s = f->sym, *p;
    size_t n;
    f->kind = 'o';
    f->cls[0] = f->meth[0] = 0;
    f->pbytes = -1;
    if (strncmp(s, "_$_", 3) == 0 || strncmp(s, "_._", 3) == 0)
    {
        f->kind = 'd';
        return;
    }
    if (s[0] == '_' && s[1] == '_' && (isdigit((unsigned char)s[2]) || s[2] == 'Q'))
    {
        f->kind = 'c';
        return;
    }
    if (!strstr(s, "__"))
    {
        if (is_ident(s) && s[0] != '_')
        {
            f->kind = 'C';
            snprintf(f->meth, sizeof f->meth, "%s", s);
        }
        return;
    }
    if (s[0] == '_')
        return;                                         /* operators, compiler-made names */
    /* the shortest name before a "__" that a class, F, C or S follows */
    for (p = s + 1; (p = strstr(p, "__")) != NULL; p++)
        if (isdigit((unsigned char)p[2]) || strchr("QFCS", p[2]))
            break;
    if (!p || p[2] == 0)
        return;
    n = (size_t)(p - s);
    if (n >= sizeof f->meth)
        return;
    memcpy(f->meth, s, n);
    f->meth[n] = 0;
    if (!is_ident(f->meth))
    {
        f->meth[0] = 0;
        return;
    }
    p += 2;
    if (*p == 'F')
    {
        f->kind = 'f';
        f->pbytes = param_bytes(p + 1);
        return;
    }
    f->kind = 'm';
    if (*p == 'C')
        p++;
    else if (*p == 'S')
    {
        f->kind = 's';
        p++;
    }
    p = read_name(p, f->cls, sizeof f->cls);
    if (!p)
    {
        f->kind = 'o';
        f->meth[0] = f->cls[0] = 0;
        return;
    }
    f->pbytes = param_bytes(p);
}

/* objects whose names are not the game's: the PS2 SDK, the compiler's run time, and open-source code */
static int usable_object(const char *obj)
{
    const char *b = obj, *q;
    if (!*obj)
        return 0;
    for (q = obj; *q; q++)
        if (*q == '\\' || *q == '/')
            b = q + 1;
    if (!strchr(b, '('))
        return strcmp(b, "crt0.o") != 0;                /* the game's own objects */
    if (strncmp(b, "lib", 3) == 0 || strncmp(b, "pngpr", 5) == 0 || strncmp(b, "zlibpr", 6) == 0)
        return 0;
    return 1;                                          /* Radical's libraries: radcore, pure3d, sim, ... */
}

typedef struct { unsigned char *d; size_t n; unsigned segs[16][3]; int nseg; } Elf;
static Elf elf;

static const unsigned char *elf_at(unsigned va, unsigned n)
{
    int i;
    if (va + n < va)
        return NULL;
    for (i = 0; i < elf.nseg; i++)
        if (elf.segs[i][1] <= va && va + n <= elf.segs[i][1] + elf.segs[i][2])
            return elf.d + elf.segs[i][0] + (va - elf.segs[i][1]);
    return NULL;
}

static unsigned rd32(const unsigned char *p) { return p[0] | p[1] << 8 | p[2] << 16 | (unsigned)p[3] << 24; }
static unsigned rd16(const unsigned char *p) { return p[0] | p[1] << 8; }

static void load_elf(const char *path)
{
    unsigned phoff, phsize, phnum, i;
    elf.d = (unsigned char *)read_file(path, &elf.n);
    if (!elf.d || elf.n < 0x40 || memcmp(elf.d, "\x7f" "ELF", 4) != 0)
        die("%s is not an ELF program", path);
    phoff = rd32(elf.d + 0x1C);
    phsize = rd16(elf.d + 0x2A);
    phnum = rd16(elf.d + 0x2C);
    for (i = 0; i < phnum && elf.nseg < 16; i++)
    {
        const unsigned char *h = elf.d + phoff + i * phsize;
        if (rd32(h) == 1)
        {
            elf.segs[elf.nseg][0] = rd32(h + 4);
            elf.segs[elf.nseg][1] = rd32(h + 8);
            elf.segs[elf.nseg][2] = rd32(h + 16);
            elf.nseg++;
        }
    }
}

static int ps2_string(unsigned va, u64 *h)
{
    const unsigned char *p = elf_at(va, 4);
    unsigned n = 0;
    if (!p)
        return 0;
    while (n < 256 && elf_at(va + n, 1) && p[n])
    {
        if (!((p[n] >= 32 && p[n] < 127) || p[n] == 9 || p[n] == 10 || p[n] == 13))
            return 0;
        n++;
    }
    if (n < 4 || n == 256 || !elf_at(va + n, 1))
        return 0;
    *h = fnv(p, n);
    return 1;
}

static void ps2_features(PF *f)
{
    const unsigned char *code = elf_at(f->va, (unsigned)f->size);
    unsigned hi[32];
    int has[32], o;
    memset(has, 0, sizeof has);
    if (!code)
        return;
    for (o = 0; o + 4 <= f->size; o += 4)
    {
        unsigned w = rd32(code + o), op = w >> 26, rs = (w >> 21) & 31, rt = (w >> 16) & 31, imm = w & 0xFFFF;
        if (op == 3)
            ul_add(&f->jals, ((f->va + o) & 0xF0000000u) | ((w & 0x3FFFFFF) << 2));
        else if (op == 0x0F)
        {
            hi[rt] = imm << 16;
            has[rt] = 1;
        }
        else if ((op == 0x09 || op == 0x0D) && has[rs])
        {
            unsigned a = hi[rs] + (op == 0x09 && (imm & 0x8000) ? imm - 0x10000 : imm);
            u64 h;
            if (ps2_string(a, &h))
                ql_add(&f->strs, h);
        }
    }
    ql_sort(&f->strs);
}

static void load_map(const char *path)
{
    char *text = read_file(path, NULL), *line, *nl;
    char obj[600] = "";
    int cap = 0, tcap = 0;
    if (!text)
        die("cannot read %s", path);
    for (line = text; *line; line = nl)
    {
        const char *e;
        unsigned a, n;
        char *w, *end;
        nl = strchr(line, '\n');
        nl = nl ? (*nl = 0, nl + 1) : line + strlen(line);
        if (strlen(line) < 20 || !isxdigit((unsigned char)line[0]) || line[8] != ' ')
            continue;
        a = hexval(line, &e);
        if (e != line + 8)
            continue;
        n = hexval(line + 9, &e);
        if (e != line + 17)
            continue;
        w = (char *)e;
        while (*w == ' ' || *w == '\t')
            w++;
        while (isdigit((unsigned char)*w))
            w++;                                         /* the alignment column */
        while (*w == ' ' || *w == '\t')
            w++;
        end = w + strlen(w);
        while (end > w && (end[-1] == ' ' || end[-1] == '\r' || end[-1] == '\t'))
            *--end = 0;
        if (!*w || *w == '.')
            continue;
        if (strchr(w, '\\') || strchr(w, '/') || (end - w > 2 && (strcmp(end - 2, ".o") == 0 || end[-1] == ')')))
        {
            snprintf(obj, sizeof obj, "%s", w);
            continue;
        }
        if (strncmp(w, "_vt$", 4) == 0)
        {
            PTab t;
            char nm[160];
            const char *r = read_name(w + 4, nm, sizeof nm);
            const unsigned char *raw = elf_at(a, n);
            unsigned i;
            if (!r || *r || !raw || n < 16 || n % 8 || rd32(raw + n - 4) != 0)
                continue;
            t.cls = xstrdup(nm);
            t.nf = (int)(n / 8) - 2;
            t.fns = (unsigned *)xmalloc((t.nf + 1) * sizeof *t.fns);
            for (i = 0; i < (unsigned)t.nf; i++)
                t.fns[i] = rd32(raw + 8 * (i + 1) + 4);
            if (nptab == tcap)
            {
                tcap = tcap * 2 + 256;
                ptab = (PTab *)xrealloc(ptab, tcap * sizeof *ptab);
            }
            ptab[nptab++] = t;
            continue;
        }
        if (!n)
            continue;
        if (npf == cap)
        {
            cap = cap * 2 + 4096;
            pf = (PF *)xrealloc(pf, cap * sizeof *pf);
        }
        memset(&pf[npf], 0, sizeof *pf);
        pf[npf].va = a;
        pf[npf].size = (int)n;
        pf[npf].sym = xstrdup(w);
        pf[npf].usable = usable_object(obj);
        npf++;
    }
    free(text);
    qsort(pf, npf, sizeof *pf, cmp_pf);
    {
        int i, j = 0;                                   /* the first symbol at an address */
        for (i = 0; i < npf; i++)
            if (!j || pf[j - 1].va != pf[i].va)
                pf[j++] = pf[i];
        npf = j;
    }
}

/* ------------------------------------------------------------------------------------- evidence */

/* hop 1 bits */
#define H1_V 1
#define H1_S 2
#define H1_G 4
/* hop 2 bits */
#define H2_I 1
#define H2_T 2
#define H2_S 4
#define H2_K 8
#define H2_G 16

typedef struct { unsigned a, b, m; } Ev;
typedef struct { Ev *e; int n, cap; } Evs;

static void ev_add(Evs *v, unsigned a, unsigned b, unsigned m)
{
    if (v->n == v->cap)
    {
        v->cap = v->cap * 2 + 1024;
        v->e = (Ev *)xrealloc(v->e, v->cap * sizeof *v->e);
    }
    v->e[v->n].a = a;
    v->e[v->n].b = b;
    v->e[v->n].m = m;
    v->n++;
}

static int cmp_ev(const void *x, const void *y)
{
    const Ev *a = (const Ev *)x, *b = (const Ev *)y;
    if (a->a != b->a)
        return a->a < b->a ? -1 : 1;
    return a->b < b->b ? -1 : a->b > b->b;
}

static int cmp_ev_b(const void *x, const void *y)
{
    const Ev *a = (const Ev *)x, *b = (const Ev *)y;
    if (a->b != b->b)
        return a->b < b->b ? -1 : 1;
    return a->a < b->a ? -1 : a->a > b->a;
}

static void ev_merge(Evs *v)
{
    int i, j = 0;
    if (!v->n)
        return;
    qsort(v->e, v->n, sizeof *v->e, cmp_ev);
    for (i = 1; i < v->n; i++)
    {
        if (v->e[i].a == v->e[j].a && v->e[i].b == v->e[j].b)
            v->e[j].m |= v->e[i].m;
        else
            v->e[++j] = v->e[i];
    }
    v->n = j + 1;
}

static int bits(unsigned m)
{
    int n = 0;
    for (; m; m >>= 1)
        n += m & 1;
    return n;
}

/* the pairs one function a has: index of the first and count */
static int ev_range(const Evs *v, unsigned a, int *cnt)
{
    int lo = 0, hi = v->n;
    while (lo < hi)
    {
        int m = (lo + hi) / 2;
        if (v->e[m].a < a)
            lo = m + 1;
        else
            hi = m;
    }
    *cnt = 0;
    while (lo + *cnt < v->n && v->e[lo + *cnt].a == a)
        (*cnt)++;
    return lo;
}

/* how many distinct a each b has: a copy sorted by b */
static int count_b(const Ev *byb, int n, unsigned b)
{
    int lo = 0, hi = n, k = 0;
    while (lo < hi)
    {
        int m = (lo + hi) / 2;
        if (byb[m].b < b)
            lo = m + 1;
        else
            hi = m;
    }
    while (lo + k < n && byb[lo + k].b == b)
        k++;
    return k;
}

/* one-function tokens: (token, owner) sorted; an owner of 0 means two or more functions use it */
typedef struct { u64 t; unsigned owner; } Tok;
typedef struct { Tok *t; int n; } Toks;

static int cmp_tok(const void *a, const void *b)
{
    u64 x = ((const Tok *)a)->t, y = ((const Tok *)b)->t;
    return x < y ? -1 : x > y;
}

static void toks_build(Toks *out, int nf, unsigned (*va_of)(int), const QL *(*list_of)(int))
{
    int i, j, k = 0, cap = 0;
    out->t = NULL;
    out->n = 0;
    for (i = 0; i < nf; i++)
    {
        const QL *l = list_of(i);
        for (j = 0; j < l->n; j++)
        {
            if (k == cap)
            {
                cap = cap * 2 + 4096;
                out->t = (Tok *)xrealloc(out->t, cap * sizeof *out->t);
            }
            out->t[k].t = l->v[j];
            out->t[k].owner = va_of(i);
            k++;
        }
    }
    if (k)
        qsort(out->t, k, sizeof *out->t, cmp_tok);
    for (i = 0, j = 0; i < k;)
    {
        int e = i;
        while (e < k && out->t[e].t == out->t[i].t)
            e++;
        out->t[j] = out->t[i];
        for (e = i + 1; e < k && out->t[e].t == out->t[i].t; e++)
            if (out->t[e].owner != out->t[i].owner)
                out->t[j].owner = 0;
        i = e;
        j++;
    }
    out->n = j;
}

static unsigned toks_owner(const Toks *ts, u64 t)
{
    Tok key, *r;
    key.t = t;
    r = ts->n ? (Tok *)bsearch(&key, ts->t, ts->n, sizeof key, cmp_tok) : NULL;
    return r ? r->owner : 0;
}

static Prog X, S;      /* Hit & Run's Xbox build, Scarface's */
static Classes XC, SC;

static unsigned pf_va(int i) { return pf[i].va; }
static const QL *pf_strs(int i) { return &pf[i].strs; }
static unsigned x_va(int i) { return X.f[i].va; }
static const QL *x_strs(int i) { return &X.f[i].strs; }
static const QL *x_consts(int i) { return &X.f[i].consts; }
static unsigned s_va(int i) { return S.f[i].va; }
static const QL *s_strs(int i) { return &S.f[i].strs; }
static const QL *s_consts(int i) { return &S.f[i].consts; }

/* -1 veto, 0 nothing to say, 1 agrees (and says something: bytes > 0) */
static int r_check(const XF *x, const PF *p)
{
    if (!x || !p || p->kind != 'm' || p->pbytes < 0 || x->nret != 1)
        return 0;
    if (x->ret == p->pbytes)
        return p->pbytes > 0 ? 1 : 0;
    if (x->ret == p->pbytes + 4)
        return 0;                                       /* a returned object's hidden pointer */
    return -1;
}

static int r2_check(const XF *a, const XF *b)
{
    if (!a || !b || a->nret != 1 || b->nret != 1)
        return 0;
    if (a->ret != b->ret)
        return -1;
    return a->ret > 0 ? 1 : 0;
}

static int same_shape(const UL *a, const UL *b)
{
    int i, j;
    if (a->n != b->n || !a->n)
        return 0;
    for (i = 0; i < a->n; i++)
        for (j = 0; j < i; j++)
            if ((a->v[i] == a->v[j]) != (b->v[i] == b->v[j]))
                return 0;
    return 1;
}

/* ---------------------------------------------------------------------------------- hop 1 result */

typedef struct { unsigned x; PF *p; unsigned m; int r; } H1;   /* r: r_check */
static H1 *h1;
static int nh1;
static Evs E1, E2;

static int h1_signals(const H1 *h) { return bits(h->m) + (h->r > 0); }

static void hop1_collect(void)
{
    Ev *byb;
    int i;
    ev_merge(&E1);
    byb = (Ev *)xmalloc((E1.n + 1) * sizeof *byb);
    memcpy(byb, E1.e, E1.n * sizeof *byb);
    qsort(byb, E1.n, sizeof *byb, cmp_ev_b);
    nh1 = 0;
    h1 = (H1 *)xrealloc(h1, (E1.n + 1) * sizeof *h1);
    for (i = 0; i < E1.n;)
    {
        int cnt, at = ev_range(&E1, E1.e[i].a, &cnt), k, live = 0, pick = -1;
        for (k = at; k < at + cnt; k++)
        {
            PF *p = pf_find(E1.e[k].b);
            if (r_check(xf_find(&X, E1.e[k].a), p) < 0)
                continue;                                /* vetoed: the parameters say no */
            live++;
            pick = k;
        }
        if (live == 1 && count_b(byb, E1.n, E1.e[pick].b) == 1)
        {
            H1 h;
            h.x = E1.e[pick].a;
            h.p = pf_find(E1.e[pick].b);
            h.m = E1.e[pick].m;
            h.r = r_check(xf_find(&X, h.x), h.p);
            h1[nh1++] = h;
        }
        i = at + cnt;
    }
    free(byb);
}

static H1 *h1_find(unsigned x)
{
    int lo = 0, hi = nh1 - 1;
    while (lo <= hi)
    {
        int m = (lo + hi) / 2;
        if (h1[m].x == x)
            return &h1[m];
        if (h1[m].x < x)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return NULL;
}

static void hop1(void)
{
    int i, j, k, round;
    Toks tp, tx;
    /* V: the PS2 function -> the Xbox functions its slots hold, over every aligned table */
    {
        Evs v;
        memset(&v, 0, sizeof v);
        for (i = 0; i < nptab; i++)
        {
            Cls *c = cls_find(&XC, ptab[i].cls);
            if (!c || c->nf != ptab[i].nf)
                continue;
            for (j = 0; j < c->nf; j++)
                ev_add(&v, ptab[i].fns[j], c->fns[j], 1);
        }
        ev_merge(&v);
        for (i = 0; i < v.n;)
        {
            int cnt;
            ev_range(&v, v.e[i].a, &cnt);
            if (cnt == 1)
            {
                PF *p = pf_find(v.e[i].a);
                if (p && p->usable && p->kind == 'm')
                    ev_add(&E1, v.e[i].b, v.e[i].a, H1_V);
            }
            i += cnt;
        }
        free(v.e);
    }
    /* S */
    toks_build(&tp, npf, pf_va, pf_strs);
    toks_build(&tx, X.n, x_va, x_strs);
    for (i = 0; i < tp.n; i++)
    {
        unsigned xo;
        PF *p;
        if (!tp.t[i].owner)
            continue;
        xo = toks_owner(&tx, tp.t[i].t);
        p = pf_find(tp.t[i].owner);
        if (xo && p && p->usable)
            ev_add(&E1, xo, p->va, H1_S);
    }
    /* G, three rounds */
    for (round = 0; round < 3; round++)
    {
        hop1_collect();
        for (i = 0; i < nh1; i++)
        {
            XF *x = xf_find(&X, h1[i].x);
            PF *p = h1[i].p;
            if (h1_signals(&h1[i]) < 2 || !x || !same_shape(&x->calls, &p->jals))
                continue;
            for (k = 0; k < x->calls.n; k++)
                if (r_check(xf_find(&X, x->calls.v[k]), pf_find(p->jals.v[k])) < 0)
                    break;
            if (k < x->calls.n)
                continue;
            for (k = 0; k < x->calls.n; k++)
            {
                PF *q = pf_find(p->jals.v[k]);
                if (q && q->usable)
                    ev_add(&E1, x->calls.v[k], q->va, H1_G);
            }
        }
    }
    hop1_collect();
    free(tp.t);
    free(tx.t);
}

/* ------------------------------------------------------------------------------- class renaming */

/* Scarface's name for a Hit & Run class by the engine's renaming rules; out "" when no rule applies */
static void renamed(const char *c, char *out, size_t cap)
{
    out[0] = 0;
    if (strncmp(c, "Scrooby::", 9) == 0 && !strstr(c + 9, "::"))
        snprintf(out, cap, "pure3d::frontend::%s", c + 9);
    else if (strncmp(c, "RadicalMathLibrary::", 20) == 0 && !strstr(c + 20, "::"))
    {
        /* math::Vector: only where Scarface's own class information names that type (template arguments) */
        char want[200];
        int i;
        snprintf(want, sizeof want, "math::%s", c + 20);
        for (i = 0; i < SC.n; i++)
        {
            const char *h = strstr(SC.c[i].name, want);
            if (h && !(isalnum((unsigned char)h[strlen(want)]) || h[strlen(want)] == '_') &&
                (h == SC.c[i].name || !(isalnum((unsigned char)h[-1]) || h[-1] == '_')))
            {
                snprintf(out, cap, "%s", want);
                return;
            }
        }
    }
    else if (strstr(c, "::") || strchr(c, '<'))
        return;
    else if (strncmp(c, "pddi", 4) == 0)
        snprintf(out, cap, "pure3d::%s", c);
    else if (c[0] == 't' && isupper((unsigned char)c[1]))
        snprintf(out, cap, "pure3d::%s", c + 1);
    else if (strncmp(c, "IRad", 4) == 0 && isupper((unsigned char)c[4]))
        snprintf(out, cap, "core::I%s", c + 4);
    else if (strncmp(c, "rad", 3) == 0 && isupper((unsigned char)c[3]))
        snprintf(out, cap, "core::%s", c + 3);
}

static const char *last_part(const char *c)
{
    const char *p = c, *q;
    while ((q = strstr(p, "::")) != NULL && !strchr(c, '<'))
        p = q + 2;
    return p;
}

/* the Scarface class with this class information name; by rule, else the same name, else the only Scarface
   class whose last name part is the same (how: 'r', 'n', 'l'); NULL when none */
static Cls *scarface_class(const char *c, char *how)
{
    char r[200];
    int i;
    Cls *found = NULL;
    renamed(c, r, sizeof r);
    if (r[0] && cls_find(&SC, r))
    {
        *how = 'r';
        return cls_find(&SC, r);
    }
    if (cls_find(&SC, c))
    {
        *how = 'n';
        return cls_find(&SC, c);
    }
    if (strchr(c, '<'))
        return NULL;
    {
        const char *lp = r[0] ? last_part(r) : last_part(c);
        for (i = 0; i < SC.n; i++)
            if (!strchr(SC.c[i].name, '<') && strcmp(last_part(SC.c[i].name), lp) == 0)
            {
                if (found)
                    return NULL;
                found = &SC.c[i];
            }
    }
    *how = 'l';
    return found;
}

/* ------------------------------------------------------------------------------------------ hop 2 */

static Cls **xc_map;    /* Hit & Run Xbox class i -> its Scarface class, NULL when none or shared */

static void hop2(void)
{
    int i, j, round;
    Toks a, b;
    /* I */
    {
        QL hx, hs;
        Tok *ts;
        memset(&hx, 0, sizeof hx);
        ts = (Tok *)xmalloc((S.n + 1) * sizeof *ts);
        for (i = 0; i < S.n; i++)
        {
            ts[i].t = S.f[i].hash;
            ts[i].owner = S.f[i].va;
        }
        qsort(ts, S.n, sizeof *ts, cmp_tok);
        for (i = 0; i < X.n; i++)
            ql_add(&hx, X.f[i].hash);
        qsort(hx.v, hx.n, sizeof *hx.v, cmp_q);
        for (i = 0; i < X.n; i++)
        {
            Tok key, *r;
            u64 h = X.f[i].hash;
            int lo = 0, hi = hx.n, nx = 0;
            if (X.f[i].size < MIN_SIZE)
                continue;
            while (lo < hi)
            {
                int m = (lo + hi) / 2;
                if (hx.v[m] < h)
                    lo = m + 1;
                else
                    hi = m;
            }
            while (lo + nx < hx.n && hx.v[lo + nx] == h)
                nx++;
            if (nx != 1)
                continue;
            key.t = h;
            r = (Tok *)bsearch(&key, ts, S.n, sizeof key, cmp_tok);
            if (!r || (r > ts && r[-1].t == h) || (r + 1 < ts + S.n && r[1].t == h))
                continue;
            ev_add(&E2, X.f[i].va, r->owner, H2_I);
        }
        free(ts);
        free(hx.v);
        memset(&hs, 0, sizeof hs);
    }
    /* T: each Hit & Run class's Scarface class, used only when no other class claims it */
    {
        Cls **map = (Cls **)xmalloc((XC.n + 1) * sizeof *map);
        for (i = 0; i < XC.n; i++)
        {
            char how;
            map[i] = scarface_class(XC.c[i].name, &how);
        }
        xc_map = (Cls **)xmalloc((XC.n + 1) * sizeof *map);
        for (i = 0; i < XC.n; i++)
        {
            xc_map[i] = map[i];
            for (j = 0; j < XC.n; j++)
                if (j != i && map[i] && map[j] == map[i])
                    xc_map[i] = NULL;
        }
        free(map);
    }
    for (i = 0; i < XC.n; i++)
    {
        Cls *o = xc_map[i], *x = &XC.c[i];
        int k;
        if (!o)
            continue;
        if (x->nf == o->nf)
        {
            for (j = 0; j < x->nf; j++)
                ev_add(&E2, x->fns[j], o->fns[j], H2_T);
            continue;
        }
        for (k = 0; k < o->nb; k++)
        {
            Cls *ob = cls_find(&SC, o->bases[k]), *xb = NULL;
            int m;
            if (!ob)
                continue;
            for (m = 0; m < x->nb; m++)
            {
                Cls *xx = cls_find(&XC, x->bases[m]);
                if (xx && xc_map[xx - XC.c] == ob)
                    xb = xx;
            }
            if (!xb || x->nf - xb->nf != o->nf - ob->nf || x->nf - xb->nf < 4)
                continue;
            for (j = 0; j < x->nf - xb->nf; j++)
                ev_add(&E2, x->fns[xb->nf + j], o->fns[ob->nf + j], H2_T);
            break;
        }
    }
    /* S, K */
    toks_build(&a, X.n, x_va, x_strs);
    toks_build(&b, S.n, s_va, s_strs);
    for (i = 0; i < a.n; i++)
    {
        unsigned so = a.t[i].owner ? toks_owner(&b, a.t[i].t) : 0;
        if (so)
            ev_add(&E2, a.t[i].owner, so, H2_S);
    }
    free(a.t);
    free(b.t);
    toks_build(&a, X.n, x_va, x_consts);
    toks_build(&b, S.n, s_va, s_consts);
    for (i = 0; i < a.n; i++)
    {
        unsigned so = a.t[i].owner ? toks_owner(&b, a.t[i].t) : 0;
        if (so)
            ev_add(&E2, a.t[i].owner, so, H2_K);
    }
    free(a.t);
    free(b.t);
    /* G */
    for (round = 0; round < 3; round++)
    {
        int n0;
        ev_merge(&E2);
        n0 = E2.n;
        for (i = 0; i < n0;)
        {
            int cnt, k;
            XF *x, *s;
            cnt = 1;                                    /* within the sorted part: what is added below is not */
            while (i + cnt < n0 && E2.e[i + cnt].a == E2.e[i].a)
                cnt++;
            if (cnt != 1 || !((E2.e[i].m & H2_I) || bits(E2.e[i].m) + (r2_check(xf_find(&X, E2.e[i].a), xf_find(&S, E2.e[i].b)) > 0) >= 2))
            {
                i += cnt;
                continue;
            }
            x = xf_find(&X, E2.e[i].a);
            s = xf_find(&S, E2.e[i].b);
            if (x && s && same_shape(&x->calls, &s->calls))
            {
                for (k = 0; k < x->calls.n; k++)
                    if (r2_check(xf_find(&X, x->calls.v[k]), xf_find(&S, s->calls.v[k])) < 0)
                        break;
                if (k == x->calls.n)
                    for (k = 0; k < x->calls.n; k++)
                        ev_add(&E2, x->calls.v[k], s->calls.v[k], H2_G);
            }
            i += cnt;
        }
    }
    ev_merge(&E2);
}

/* ------------------------------------------------------------------------------ project's names */

typedef struct { unsigned va; char *name; char *by; } Name;
static Name *nm;
static int nnm;
static char *names_text;
static UL lib_list;

typedef struct { unsigned va; char *sym; } Sym;
static Sym *syms;
static int nsyms;

static int cmp_name(const void *a, const void *b)
{
    unsigned x = ((const Name *)a)->va, y = ((const Name *)b)->va;
    return x < y ? -1 : x > y;
}

static Name *name_of(unsigned va)
{
    Name key;
    key.va = va;
    return nnm ? (Name *)bsearch(&key, nm, nnm, sizeof key, cmp_name) : NULL;
}

static int name_taken(const char *s)
{
    int i;
    for (i = 0; i < nnm; i++)
        if (strcmp(nm[i].name, s) == 0)
            return 1;
    return 0;
}

static char *json_str(const char *p, const char **end)
{
    Buf b = { 0, 0, 0 };
    if (*p != '"')
        return NULL;
    for (p++; *p && *p != '"'; p++)
    {
        if (*p == '\\' && p[1])
            p++;
        buf_add(&b, p, 1);
    }
    if (end)
        *end = *p ? p + 1 : p;
    if (!b.p)
        buf_add(&b, "", 0);
    return b.p;
}

static void load_names(const char *repo)
{
    char path[1024];
    const char *p;
    int cap = 0;
    snprintf(path, sizeof path, "%s/reports/names.json", repo);
    names_text = read_file(path, NULL);
    if (!names_text)
        die("cannot read %s", path);
    p = strstr(names_text, "\"names\": {");
    if (!p)
        die("names.json has no names object");
    while ((p = strstr(p, "\"xb:0x")) != NULL)
    {
        unsigned va = hexval(p + 6, NULL);
        const char *q = strchr(p, '{'), *n, *b, *nx;
        if (!q)
            break;
        nx = strstr(q, "\"xb:0x");
        n = strstr(q, "\"name\": ");
        b = strstr(q, "\"by\": ");
        p += 6;
        if (!n || !b || (nx && (n > nx || b > nx)))
            continue;
        if (nnm == cap)
        {
            cap = cap * 2 + 1024;
            nm = (Name *)xrealloc(nm, cap * sizeof *nm);
        }
        nm[nnm].va = va;
        nm[nnm].name = json_str(n + 8, NULL);
        nm[nnm].by = json_str(b + 6, NULL);
        nnm++;
    }
    qsort(nm, nnm, sizeof *nm, cmp_name);
    snprintf(path, sizeof path, "%s/reports/library_functions.json", repo);
    {
        char *t = read_file(path, NULL);
        const char *s, *e;
        if (!t)
            die("cannot read %s", path);
        s = strstr(t, "\"xb\": [");
        e = s ? strchr(s, ']') : NULL;
        while (s && (s = strstr(s, "\"0x")) != NULL && s < e)
        {
            ul_add(&lib_list, hexval(s + 1, NULL));
            s += 3;
        }
        ul_sort(&lib_list);
        free(t);
    }
}

static int cmp_sym(const void *a, const void *b)
{
    unsigned x = ((const Sym *)a)->va, y = ((const Sym *)b)->va;
    return x < y ? -1 : x > y;
}

/* the class information's names (Class::vfunc_NN) and matched names, from the address-order list */
static void load_symbols(const char *repo)
{
    char path[1024], *text, *line, *nl;
    int cap = 0;
    snprintf(path, sizeof path, "%s/reconstructed_src/Original_Binary_Order_Xbox.cpp", repo);
    text = read_file(path, NULL);
    if (!text)
        die("cannot read %s", path);
    for (line = text; *line; line = nl)
    {
        char sym[512];
        unsigned va = 0;
        int ok = 0;
        nl = strchr(line, '\n');
        nl = nl ? nl + 1 : line + strlen(line);
        if (strncmp(line, "// [TODO] 0x", 12) == 0)
        {
            const char *e;
            va = hexval(line + 10, &e);
            ok = sscanf(e, " %511s", sym) == 1;
        }
        else if (strncmp(line, "// [VERIFIED] ", 14) == 0)
        {
            const char *o = strstr(line + 14, " (0x");
            if (o && o - (line + 14) < 511)
            {
                memcpy(sym, line + 14, (size_t)(o - (line + 14)));
                sym[o - (line + 14)] = 0;
                va = hexval(o + 2, NULL);
                ok = 1;
            }
        }
        if (!ok || strncmp(sym, "sub_", 4) == 0)
            continue;
        if (nsyms == cap)
        {
            cap = cap * 2 + 1024;
            syms = (Sym *)xrealloc(syms, cap * sizeof *syms);
        }
        syms[nsyms].va = va;
        syms[nsyms].sym = xstrdup(sym);
        nsyms++;
    }
    free(text);
    qsort(syms, nsyms, sizeof *syms, cmp_sym);
}

static const char *symbol_of(unsigned va)
{
    Sym key, *r;
    key.va = va;
    r = nsyms ? (Sym *)bsearch(&key, syms, nsyms, sizeof key, cmp_sym) : NULL;
    return r ? r->sym : NULL;
}

/* "Class" out of "Class::vfunc_NN"; 0 when the symbol is not a slot name */
static int slot_class(const char *sym, char *cls, size_t cap)
{
    const char *v = sym ? strstr(sym, "::vfunc_") : NULL;
    if (!v || (size_t)(v - sym) >= cap)
        return 0;
    memcpy(cls, sym, (size_t)(v - sym));
    cls[v - sym] = 0;
    return 1;
}

static int lib_function(unsigned va, const XF *s)
{
    Name *n = name_of(va);
    if (s && s->lib)
        return 1;
    if (ul_has(&lib_list, va))
        return 1;
    return n && (strncmp(n->by, "Xbox SDK", 8) == 0 || strncmp(n->by, "symcov", 6) == 0);
}

/* ------------------------------------------------------------------------------------- decisions */

typedef struct
{
    unsigned s, x;
    PF *p;
    unsigned m1, m2;
    int r1, r2;
    char name[400];
    char why[1600];
    char verdict;       /* W written, H hint, D disagrees with an existing name, A agrees with an existing name, N
                           not usable (no name to give, taken, overload) */
    const char *note;
} Chain;

static Chain *ch;
static int nch;

static void methods1(const Chain *c, char *out)
{
    out[0] = 0;
    if (c->m1 & H1_V) strcat(out, "V");
    if (c->m1 & H1_S) strcat(out, "S");
    if (c->r1 > 0) strcat(out, "R");
    if (c->m1 & H1_G) strcat(out, "G");
}

static void methods2(const Chain *c, char *out)
{
    out[0] = 0;
    if (c->m2 & H2_I) strcat(out, "I");
    if (c->m2 & H2_T) strcat(out, "T");
    if (c->m2 & H2_S) strcat(out, "S");
    if (c->m2 & H2_K) strcat(out, "K");
    if (c->r2 > 0) strcat(out, "R");
    if (c->m2 & H2_G) strcat(out, "G");
}

static const char *M1WORDS[] = { "V", "the same slot of the class's table of virtual functions in both builds",
                                 "S", "a string only it uses on each side",
                                 "R", "its parameter list adds up to the bytes the Xbox function's ret removes",
                                 "G", "the same place in the call graph under a function paired the same way", NULL };
static const char *M2WORDS[] = { "I", "identical code (addresses apart), found once in each program",
                                 "T", "the same slot of the same class's table of virtual functions",
                                 "S", "a string only it uses in each program",
                                 "K", "a constant only it uses in each program",
                                 "R", "the same ret N",
                                 "G", "the same place in the call graph under a function paired the same way", NULL };

static void describe(Buf *b, const char *ms, const char **words)
{
    int i, first = 1;
    for (; *ms; ms++)
        for (i = 0; words[i]; i += 2)
            if (words[i][0] == *ms)
            {
                buf_puts(b, first ? "" : "; ");
                buf_puts(b, words[i + 1]);
                first = 0;
            }
}

static int cmp_chain(const void *a, const void *b)
{
    unsigned x = ((const Chain *)a)->s, y = ((const Chain *)b)->s;
    return x < y ? -1 : x > y;
}

/* the Scarface form of a PS2 class (by the renaming rules, else as it is) */
static void scarface_form(const char *cls, char *out, size_t cap)
{
    char how;
    Cls *c;
    renamed(cls, out, cap);
    if (out[0])
        return;
    c = scarface_class(cls, &how);
    snprintf(out, cap, "%s", c ? c->name : cls);
}

/* the rule for a name: two signals on hop 1; on hop 2 identical code, or the table slot with the same ret N.
   Hop 2's strings, constants and call graph never met a recorded name they agreed with (measured: S 0/1, K 0/1,
   G 0/0), so they only make hints. */
static int meets_rule(const Chain *c)
{
    int strong1 = bits(c->m1) + (c->r1 > 0) >= 2;
    int strong2 = (c->m2 & H2_I) || ((c->m2 & H2_T) && c->r2 > 0);
    return strong1 && strong2;
}

static void decide(void)
{
    Ev *byb;
    int i, cap = 0;
    byb = (Ev *)xmalloc((E2.n + 1) * sizeof *byb);
    memcpy(byb, E2.e, E2.n * sizeof *byb);
    qsort(byb, E2.n, sizeof *byb, cmp_ev_b);
    for (i = 0; i < nh1; i++)
    {
        int cnt, at, k, live = 0, pick = -1;
        Chain c;
        XF *x = xf_find(&X, h1[i].x), *s;
        Name *old;
        const char *sym;
        char sc[300], form[300], m1[8], m2[8];
        Buf w = { 0, 0, 0 };
        if (!x || x->size < MIN_SIZE)
            continue;
        at = ev_range(&E2, h1[i].x, &cnt);
        for (k = at; k < at + cnt; k++)
        {
            if (r2_check(x, xf_find(&S, E2.e[k].b)) < 0)
                continue;
            live++;
            pick = k;
        }
        if (live != 1 || count_b(byb, E2.n, E2.e[pick].b) != 1)
            continue;
        s = xf_find(&S, E2.e[pick].b);
        if (!s || s->size < MIN_SIZE)
            continue;
        memset(&c, 0, sizeof c);
        c.s = s->va;
        c.x = x->va;
        c.p = h1[i].p;
        c.m1 = h1[i].m;
        c.r1 = h1[i].r;
        c.m2 = E2.e[pick].m;
        c.r2 = r2_check(x, s);
        methods1(&c, m1);
        methods2(&c, m2);
        if (!c.p->meth[0] || !(c.p->kind == 'm' || c.p->kind == 's' || c.p->kind == 'f' || c.p->kind == 'C'))
        {
            c.verdict = 'N';
            c.note = "the PS2 symbol has no plain name (constructor, destructor, operator)";
        }
        form[0] = 0;
        if (c.p->cls[0])
            scarface_form(c.p->cls, form, sizeof form);
        /* the class information's class of the Scarface function must agree */
        sym = symbol_of(s->va);
        if (!c.verdict && slot_class(sym, sc, sizeof sc))
        {
            Cls *own = cls_find(&SC, sc), *mine = form[0] ? cls_find(&SC, form) : NULL;
            if (!form[0])
            {
                c.verdict = 'D';
                c.note = "the class information files it under a class; the PS2 symbol has none";
            }
            else if (strcmp(sc, form) == 0 || cls_has_base(own, form) || cls_has_base(mine, sc))
                ;
            else if (strcmp(last_part(sc), last_part(form)) == 0)
                snprintf(form, sizeof form, "%s", sc);  /* the same class in another namespace */
            else
            {
                c.verdict = 'D';
                c.note = "the class information files it under another class";
            }
        }
        if (form[0])
            snprintf(c.name, sizeof c.name, "%s::%s", form, c.p->meth);
        else
            snprintf(c.name, sizeof c.name, "%s", c.p->meth);
        old = name_of(s->va);
        if (!c.verdict && old)
        {
            const char *a = last_part(old->name), *b = c.p->meth;
#ifdef _WIN32
            c.verdict = _stricmp(a, b) == 0 ? 'A' : 'D';
#else
            c.verdict = strcasecmp(a, b) == 0 ? 'A' : 'D';
#endif
            c.note = c.verdict == 'A' ? "agrees with the name recorded" : "disagrees with the name recorded";
        }
        if (!c.verdict)
        {
            c.verdict = meets_rule(&c) ? 'W' : 'H';
        }
        buf_addf(&w, "Hit & Run's 10 July 2003 PS2 prototype has a linker map (SRR2.MAP); its %s pairs with the "
                     "function at 0x%08X of Hit & Run's retail Xbox build by ", c.p->sym, c.x);
        describe(&w, m1, M1WORDS);
        buf_puts(&w, ", and that function pairs with this one by ");
        describe(&w, m2, M2WORDS);
        buf_puts(&w, ".");
        snprintf(c.why, sizeof c.why, "%s", w.p);
        free(w.p);
        if (nch == cap)
        {
            cap = cap * 2 + 256;
            ch = (Chain *)xrealloc(ch, cap * sizeof *ch);
        }
        ch[nch++] = c;
    }
    free(byb);
    qsort(ch, nch, sizeof *ch, cmp_chain);
    /* a name given to two functions (overloads, or two classes' copies) is given to neither */
    for (i = 0; i < nch; i++)
    {
        int j;
        if (ch[i].verdict != 'W' && ch[i].verdict != 'H')
            continue;
        for (j = 0; j < nch; j++)
            if (j != i && (ch[j].verdict == 'W' || ch[j].verdict == 'H' || ch[j].verdict == 'n') &&
                strcmp(ch[i].name, ch[j].name) == 0)
                break;
        if (j < nch || name_taken(ch[i].name))
        {
            ch[i].verdict = 'n';
            ch[i].note = j < nch ? "the same name would go to two functions" : "the name is already another function's";
        }
    }
    for (i = 0; i < nch; i++)
        if (ch[i].verdict == 'n')
            ch[i].verdict = 'N';
}

/* -------------------------------------------------------------------------------------- reporting */

static void count_hop1(void)
{
    int i, k, n[32];
    memset(n, 0, sizeof n);
    for (i = 0; i < nh1; i++)
    {
        XF *x = xf_find(&X, h1[i].x);
        if (!x || x->size < MIN_SIZE)
            continue;
        n[(h1[i].m & 7) | (h1[i].r > 0 ? 8 : 0)]++;
    }
    printf("Hop 1 (PS2 symbol -> Hit & Run Xbox function, one to one, 24 bytes or more), by the signals each has\n"
           "  (V slot, S string, R parameters against ret N, G call graph):\n");
    for (k = 1; k < 16; k++)
    {
        char m[8] = "";
        if (!n[k])
            continue;
        if (k & H1_V) strcat(m, "V");
        if (k & H1_S) strcat(m, "S");
        if (k & 8) strcat(m, "R");
        if (k & H1_G) strcat(m, "G");
        printf("    %-5s %5d%s\n", m, n[k], bits((unsigned)k) >= 2 ? "  (two signals)" : "");
    }
    {
        int two = 0, all = 0;
        for (k = 1; k < 16; k++)
        {
            all += n[k];
            two += bits((unsigned)k) >= 2 ? n[k] : 0;
        }
        printf("    total %d, with two signals or more %d\n", all, two);
    }
}

/* hop 1 methods against each other: where a function has V and another method pairs it, the same PS2 function? */
static void cross_hop1(void)
{
    int i, agreeS = 0, disS = 0, agreeG = 0, disG = 0, agreeR = 0, disR = 0;
    for (i = 0; i < E1.n;)
    {
        int cnt, at = ev_range(&E1, E1.e[i].a, &cnt), k;
        unsigned vp = 0;
        XF *x = xf_find(&X, E1.e[i].a);
        int nv = 0;
        for (k = at; k < at + cnt; k++)
            if (E1.e[k].m & H1_V)
            {
                vp = E1.e[k].b;
                nv++;
            }
        if (nv == 1 && x && x->size >= MIN_SIZE)
        {
            int r = r_check(x, pf_find(vp));
            agreeR += r > 0;
            disR += r < 0;
            for (k = at; k < at + cnt; k++)
            {
                if (E1.e[k].m & H1_S)
                {
                    if (E1.e[k].b == vp) agreeS++; else disS++;
                }
                if (E1.e[k].m & H1_G)
                {
                    if (E1.e[k].b == vp) agreeG++; else disG++;
                }
            }
        }
        i = at + cnt;
    }
    printf("  hop 1 methods checked against V (the slot), Xbox functions of 24 bytes or more:\n"
           "    S names the same PS2 function %d times, another %d times\n"
           "    G names the same PS2 function %d times, another %d times\n"
           "    R (parameters against ret N, bytes > 0) agrees %d times, contradicts %d times\n",
           agreeS, disS, agreeG, disG, agreeR, disR);
}

static void identical_code(void)
{
    int i, lib = 0, game = 0, libn = 0, gamen = 0;
    for (i = 0; i < E2.n; i++)
    {
        XF *s;
        if (!(E2.e[i].m & H2_I))
            continue;
        s = xf_find(&S, E2.e[i].b);
        if (lib_function(E2.e[i].b, s))
        {
            lib++;
            libn += name_of(E2.e[i].b) != NULL;
        }
        else
        {
            game++;
            gamen += name_of(E2.e[i].b) != NULL;
        }
    }
    printf("Identical code (addresses masked), 24 bytes or more, found once in each Xbox program: %d\n"
           "    library code (Microsoft's, zlib/libpng; reports/library_functions.json or a library name): %d (%d named already)\n"
           "    game and engine code: %d (%d named already)\n", lib + game, lib, libn, game, gamen);
}

static void accuracy(int list)
{
    int i, k;
    int a1[4][2], a2[6][2];
    const char *n1 = "VSRG", *n2 = "ITSKRG";
    memset(a1, 0, sizeof a1);
    memset(a2, 0, sizeof a2);
    for (i = 0; i < nch; i++)
    {
        char m1[8], m2[8];
        int ok;
        if (ch[i].verdict != 'A' && ch[i].verdict != 'D')
            continue;
        ok = ch[i].verdict == 'A';
        methods1(&ch[i], m1);
        methods2(&ch[i], m2);
        for (k = 0; k < 4; k++)
            if (strchr(m1, n1[k]))
                a1[k][ok]++;
        for (k = 0; k < 6; k++)
            if (strchr(m2, n2[k]))
                a2[k][ok]++;
    }
    printf("Accuracy against names the project already has (names.json, or the class of a Class::vfunc_NN slot),\n"
           "for every one-to-one chain, any number of signals (agree / disagree):\n  hop 1:");
    for (k = 0; k < 4; k++)
        printf("  %c %d/%d", n1[k], a1[k][1], a1[k][0]);
    printf("\n  hop 2:");
    for (k = 0; k < 6; k++)
        printf("  %c %d/%d", n2[k], a2[k][1], a2[k][0]);
    printf("\n");
    {
        int agree = 0, dis = 0, none = 0, total = 0;
        for (i = 0; i < nnm; i++)
        {
            int j;
            if (strcmp(nm[i].by, "the Hit & Run prototype's linker map") != 0)
                continue;
            total++;
            for (j = 0; j < nch; j++)
                if (ch[j].s == nm[i].va)
                    break;
            if (j == nch)
                none++;
            else if (ch[j].verdict == 'A')
                agree++;
            else
                dis++;
        }
        int ra = 0, rd = 0;
        for (i = 0; i < nch; i++)
            if ((ch[i].verdict == 'A' || ch[i].verdict == 'D') && meets_rule(&ch[i]))
            {
                ra += ch[i].verdict == 'A';
                rd += ch[i].verdict == 'D';
            }
        printf("  chains that meet the rule for a name: agree %d, disagree %d\n", ra, rd);
        printf("  of the %d names from the map (names_from_shar_map.py): the bridge reaches %d, agrees on %d, disagrees on %d\n",
               total, agree + dis, agree, dis);
    }
    for (i = 0; i < nch; i++)
    {
        char m1[8], m2[8];
        if (ch[i].verdict != 'D')
            continue;
        methods1(&ch[i], m1);
        methods2(&ch[i], m2);
        if (list)
            printf("  DISAGREE xb:0x%08X  has %s; the bridge says %s (%s, via 0x%08X, hop 1 %s, hop 2 %s): %s\n", ch[i].s,
                   name_of(ch[i].s) ? name_of(ch[i].s)->name : symbol_of(ch[i].s), ch[i].name, ch[i].p->sym, ch[i].x,
                   m1, m2, ch[i].note);
    }
}

/* ------------------------------------------------------------------------------------------- main */

static void usage(void)
{
    fprintf(stderr, "usage: shar_bridge --map SRR2.MAP --elf SLUS_206.24 --shar default.xbe [--repo DIR] "
                    "[--refresh] [--list] [--write]\n");
    exit(2);
}

static int exists(const char *p)
{
    FILE *f = fopen(p, "rb");
    if (f)
        fclose(f);
    return f != NULL;
}

int main(int argc, char **argv)
{
    const char *repo = ".";
    const char *mapf = NULL;
    const char *elff = NULL;
    const char *sharf = NULL;
    int write = 0, list = 0, refresh = 0, i, nw = 0, nh = 0, nd = 0, na = 0, nn = 0;
    char px[1024], ps[1024], path[1024], vt[1100];
    for (i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "--repo") && i + 1 < argc) repo = argv[++i];
        else if (!strcmp(argv[i], "--map") && i + 1 < argc) mapf = argv[++i];
        else if (!strcmp(argv[i], "--elf") && i + 1 < argc) elff = argv[++i];
        else if (!strcmp(argv[i], "--shar") && i + 1 < argc) sharf = argv[++i];
        else if (!strcmp(argv[i], "--write")) write = 1;
        else if (!strcmp(argv[i], "--list")) list = 1;
        else if (!strcmp(argv[i], "--refresh")) refresh = 1;
        else usage();
    }
    if (!mapf || !elff || !sharf)
    {
        fprintf(stderr, "shar_bridge: --map, --elf and --shar are required (your own copies of Hit & Run's files)\n");
        usage();
    }
    snprintf(px, sizeof px, "%s/build/shar_bridge/shar_xbox.tsv", repo);
    snprintf(ps, sizeof ps, "%s/build/shar_bridge/scarface_xbox.tsv", repo);
    make_dirs_for(px);
    if (refresh || !exists(px))
    {
        printf("measuring Hit & Run's Xbox program (a few minutes)...\n");
        fflush(stdout);
        run_bridge(repo, "shar", sharf, px);
    }
    if (refresh || !exists(ps))
    {
        snprintf(path, sizeof path, "%s/binaries/default.xbe", repo);
        printf("measuring binaries/default.xbe...\n");
        fflush(stdout);
        run_bridge(repo, "sf", path, ps);
    }
    load_prog(px, &X);
    load_prog(ps, &S);
    snprintf(vt, sizeof vt, "%s.vt", px);
    load_classes(vt, &XC);
    snprintf(vt, sizeof vt, "%s.vt", ps);
    load_classes(vt, &SC);
    load_elf(elff);
    load_map(mapf);
    for (i = 0; i < npf; i++)
    {
        demangle(&pf[i]);
        ps2_features(&pf[i]);
    }
    load_names(repo);
    load_symbols(repo);
    {
        int paired = 0, same = 0;
        for (i = 0; i < nptab; i++)
        {
            Cls *c = cls_find(&XC, ptab[i].cls);
            paired += c != NULL;
            same += c && c->nf == ptab[i].nf;
        }
        printf("PS2 map: %d symbols, %d tables of virtual functions; Hit & Run Xbox: %d functions, %d classes; "
               "Scarface Xbox: %d functions, %d classes\n", npf, nptab, X.n, XC.n, S.n, SC.n);
        printf("Classes with the same name in both Hit & Run builds: %d, with the same number of slots: %d\n", paired, same);
    }
    hop1();
    hop2();
    count_hop1();
    cross_hop1();
    identical_code();
    decide();
    accuracy(list);
    for (i = 0; i < nch; i++)
    {
        char m1[8], m2[8];
        methods1(&ch[i], m1);
        methods2(&ch[i], m2);
        nw += ch[i].verdict == 'W';
        nh += ch[i].verdict == 'H';
        nd += ch[i].verdict == 'D';
        na += ch[i].verdict == 'A';
        nn += ch[i].verdict == 'N';
        if (list && ch[i].verdict != 'D')
            printf("  %c xb:0x%08X  %-60s hop1 %-4s hop2 %-5s %s %s\n", ch[i].verdict, ch[i].s, ch[i].name, m1, m2,
                   ch[i].p->sym, ch[i].note ? ch[i].note : "");
    }
    printf("Chains (one to one on both hops, 24 bytes or more): %d. Names to write %d, hints %d, agree with a recorded "
           "name %d, disagree %d, not usable %d\n", nch, nw, nh, na, nd, nn);
    {
        int byk[2][8];
        const char *kn = "VSRG";
        memset(byk, 0, sizeof byk);
        for (i = 0; i < nch; i++)
        {
            char m1[8], m2[8];
            int w = ch[i].verdict == 'W' ? 0 : ch[i].verdict == 'H' ? 1 : -1, k;
            if (w < 0)
                continue;
            methods1(&ch[i], m1);
            methods2(&ch[i], m2);
            for (k = 0; k < 4; k++)
                byk[w][k] += strchr(m1, kn[k]) != NULL;
            byk[w][4] += strchr(m2, 'I') != NULL;
            byk[w][5] += strchr(m2, 'T') != NULL;
            byk[w][6] += (strchr(m2, 'S') || strchr(m2, 'K')) != 0;
            byk[w][7] += strchr(m2, 'G') != NULL;
        }
        for (i = 0; i < 2; i++)
            printf("  %s by method: hop 1 V %d S %d R %d G %d; hop 2 I %d T %d S/K %d G %d\n", i ? "hints" : "names",
                   byk[i][0], byk[i][1], byk[i][2], byk[i][3], byk[i][4], byk[i][5], byk[i][6], byk[i][7]);
    }
    if (!write)
        return 0;
    /* names.json: the new entries go at the end of "names" */
    {
        Buf nb = { 0, 0, 0 };
        const char *nmo = strstr(names_text, "\"names\": {"), *q;
        int depth = 0, instr = 0, added = 0;
        size_t at;
        for (q = strchr(nmo, '{'); *q; q++)
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
        for (i = 0; i < nch; i++)
        {
            if (ch[i].verdict != 'W')
                continue;
            buf_addf(&nb, ",\n    \"xb:0x%08X\": {\n      \"name\": \"", ch[i].s);
            buf_json(&nb, ch[i].name);
            buf_puts(&nb, "\",\n      \"by\": \"");
            buf_json(&nb, BY);
            buf_puts(&nb, "\",\n      \"why\": \"");
            buf_json(&nb, ch[i].why);
            buf_puts(&nb, "\"\n    }");
            added++;
        }
        buf_puts(&nb, names_text + at);
        if (added)
        {
            snprintf(path, sizeof path, "%s/reports/names.json", repo);
            write_file(path, nb.p, nb.n);
        }
        printf("names.json: %d names added\n", added);
    }
    {
        Buf hb = { 0, 0, 0 };
        int first = 1;
        buf_puts(&hb, "{\n  \"schema\": \"scarface_shar_bridge_hints_v1\",\n"
                      "  \"note\": \"What Hit & Run's 10 July 2003 PS2 prototype's linker map calls a function, carried through Hit & Run's "
                      "retail Xbox build, where the evidence is one signal on a hop: a hint to what the code does, never a name. "
                      "hop1 (PS2 symbol to Hit & Run Xbox): V slot of a table of virtual functions, S a string only it uses, R its "
                      "parameters against the bytes its ret removes, G call graph. hop2 (Hit & Run Xbox to Scarface): I identical code, "
                      "T table slot of the same class under the engine's renaming, S string, K constant, R the same ret N, G call graph. "
                      "Made by tools/shar_bridge.c.\",\n  \"hints\": {");
        for (i = 0; i < nch; i++)
        {
            char m1[8], m2[8];
            if (ch[i].verdict != 'H')
                continue;
            methods1(&ch[i], m1);
            methods2(&ch[i], m2);
            buf_addf(&hb, "%s\n    \"xb:0x%08X\": {\n      \"hint\": \"", first ? "" : ",", ch[i].s);
            buf_json(&hb, ch[i].name);
            buf_puts(&hb, "\",\n      \"ps2_symbol\": \"");
            buf_json(&hb, ch[i].p->sym);
            buf_addf(&hb, "\",\n      \"hop1\": \"%s\",\n      \"hop2\": \"%s\",\n      \"by\": \"", m1, m2);
            buf_json(&hb, BY);
            buf_puts(&hb, "\",\n      \"why\": \"");
            buf_json(&hb, ch[i].why);
            buf_puts(&hb, "\"\n    }");
            first = 0;
        }
        buf_puts(&hb, "\n  }\n}\n");
        snprintf(path, sizeof path, "%s/reports/shar_bridge_hints.json", repo);
        write_file(path, hb.p, hb.n);
        printf("shar_bridge_hints.json: %d hints\n", nh);
    }
    return 0;
}
