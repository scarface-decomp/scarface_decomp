// bin: xb
// va: 0x002C6A20
// what: Copies a block of memory for the PNG image library after checking that its length fits (libpng png_memcpy_check).
// tool: Claude Opus 5.5

#include <string.h>

// libpng's types, as png.h / pngconf.h declare them.
typedef unsigned long png_uint_32;
typedef size_t png_size_t;
typedef void *png_voidp;
typedef struct png_struct_def png_struct;
typedef png_struct *png_structp;

#define png_memcpy memcpy

extern "C" void __cdecl png_error(png_structp png_ptr, const char *error_message);

// pngmem.c: memcpy that refuses a length the platform's size type cannot hold.
extern "C" png_voidp __cdecl png_memcpy_check(png_structp png_ptr, png_voidp s1, png_voidp s2,
    png_uint_32 length)
{
    png_size_t size;

    size = (png_size_t)length;
    if ((png_uint_32)size != length)
        png_error(png_ptr, "Overflow in png_memcpy_check.");

    return (png_memcpy(s1, s2, size));
}
