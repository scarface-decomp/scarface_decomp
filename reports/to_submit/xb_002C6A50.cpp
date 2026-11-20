// bin: xb
// va: 0x002C6A50
// what: Fills a block of memory for the PNG image library after checking that its length fits (libpng png_memset_check).
// tool: Claude Opus 5.5

#include <string.h>

// libpng's types, as png.h / pngconf.h declare them.
typedef unsigned long png_uint_32;
typedef size_t png_size_t;
typedef void *png_voidp;
typedef struct png_struct_def png_struct;
typedef png_struct *png_structp;

#define png_memset memset

extern "C" void __cdecl png_error(png_structp png_ptr, const char *error_message);

// pngmem.c: memset that refuses a length the platform's size type cannot hold.
extern "C" png_voidp __cdecl png_memset_check(png_structp png_ptr, png_voidp s1, int value,
    png_uint_32 length)
{
    png_size_t size;

    size = (png_size_t)length;
    if ((png_uint_32)size != length)
        png_error(png_ptr, "Overflow in png_memset_check.");

    return (png_memset(s1, value, size));
}
