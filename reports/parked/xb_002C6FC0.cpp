// parked: 22/277 bytes per file; the same zlib 1.2.1 body as a static function compiled with cl /GL and linked with link /LTCG gives 277/277 bytes with 'out' in eax (experiment 2026-11-19, work/ltcg/), so the wall is the per-file verifier's lack of an LTCG mode, not the source.
// bin: xb
// va: 0x002C6FC0
// what: Copies the newest decompressed bytes into zlib's sliding window so later back-references can reach them (zlib updatewindow).
// tool: Claude Opus 5.5

#include <string.h>

// zlib 1.2.1's types, as zlib.h / zconf.h / zutil.h / inflate.h declare them (only the parts used here;
// the field offsets in the bytes fit 1.2.1's inflate_state, which has no dmax and no head yet).
typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;
typedef void *voidpf;
typedef voidpf (*alloc_func)(voidpf opaque, uInt items, uInt size);
typedef void (*free_func)(voidpf opaque, voidpf address);

#define Z_NULL 0
#define FAR
#define local static
#define zmemcpy memcpy
#define ZALLOC(strm, items, size) \
           (*((strm)->zalloc))((strm)->opaque, (items), (size))

struct internal_state;

typedef struct z_stream_s {
    Byte    *next_in;
    uInt     avail_in;
    uLong    total_in;
    Byte    *next_out;
    uInt     avail_out;
    uLong    total_out;
    char     *msg;
    struct internal_state FAR *state;
    alloc_func zalloc;
    free_func  zfree;
    voidpf     opaque;
    int     data_type;
    uLong   adler;
    uLong   reserved;
} z_stream;

typedef z_stream FAR *z_streamp;

typedef enum {
    HEAD
} inflate_mode;

struct inflate_state {
    inflate_mode mode;
    int last;
    int wrap;
    int havedict;
    int flags;
    unsigned long check;
    unsigned long total;
    unsigned wbits;
    unsigned wsize;
    unsigned whave;
    unsigned write;
    unsigned char FAR *window;
};

// zlib declares it "local" (static); it is written extern here so that the file emits it alone.
// PARKED: retail passes 'out' in eax (a /GL whole-program register convention for this static
// function); cl without /GL always passes it on the stack. The body is zlib's own.
int updatewindow(z_streamp strm, unsigned out)
{
    struct inflate_state FAR *state;
    unsigned copy, dist;

    state = (struct inflate_state FAR *)strm->state;

    /* if it hasn't been done already, allocate space for the window */
    if (state->window == Z_NULL) {
        state->window = (unsigned char FAR *)
                        ZALLOC(strm, 1U << state->wbits,
                               sizeof(unsigned char));
        if (state->window == Z_NULL) return 1;
    }

    /* if window not in use yet, initialize */
    if (state->wsize == 0) {
        state->wsize = 1U << state->wbits;
        state->write = 0;
        state->whave = 0;
    }

    /* copy state->wsize or less output bytes into the circular window */
    copy = out - strm->avail_out;
    if (copy >= state->wsize) {
        zmemcpy(state->window, strm->next_out - state->wsize, state->wsize);
        state->write = 0;
        state->whave = state->wsize;
    }
    else {
        dist = state->wsize - state->write;
        if (dist > copy) dist = copy;
        zmemcpy(state->window + state->write, strm->next_out - copy, dist);
        copy -= dist;
        if (copy) {
            zmemcpy(state->window, strm->next_out - copy, copy);
            state->write = copy;
            state->whave = state->wsize;
        }
        else {
            state->write += dist;
            if (state->write == state->wsize) state->write = 0;
            if (state->whave < state->wsize) state->whave += dist;
        }
    }
    return 0;
}

