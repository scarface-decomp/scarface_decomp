// verify: python portal/verify.py reports/to_submit/xb_002CA770.cpp --va 0x002CA770 --bin xb --match '_png_handle_sPLT' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002CA770
// what: Reads a PNG file's sPLT chunk (suggested palettes), checks it and stores it (libpng png_handle_sPLT, with the game's one change: an unsigned length).
// tool: Claude Opus 5.5 (the public libpng 1.2.8 source of this function, altered in one line; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others; under the libpng licence.
// THIS IS AN ALTERED VERSION of libpng's png_handle_sPLT (pngrutil.c), as the licence requires it to be marked.
// The game's copy declares data_length as png_uint_32 where libpng 1.2.8 (and every release up to 1.2.30)
// declares it int: the remainder and the division by entry_size are unsigned in the game's bytes. With that
// one change the published function compiles to the game's bytes exactly; unchanged, 319 bytes differ.

// The published file is compiled first, its own png_handle_sPLT renamed out of the way, so that the functions
// this one calls are defined above it as they were in the game's file; then the altered function follows.
#define png_handle_sPLT png_handle_sPLT_as_published
#include "libpng-1.2.8/pngrutil.c"
#undef png_handle_sPLT

void /* PRIVATE */
png_handle_sPLT(png_structp png_ptr, png_infop info_ptr, png_uint_32 length)
/* Note: this does not properly handle chunks that are > 64K under DOS */
{
   png_bytep chunkdata;
   png_bytep entry_start;
   png_sPLT_t new_palette;
#ifdef PNG_NO_POINTER_INDEXING
   png_sPLT_entryp pp;
#endif
   png_uint_32 data_length;  /* ALTERED: int in libpng 1.2.8 (see the note above) */
   int entry_size, i;
   png_uint_32 skip = 0;
   png_size_t slength;

   png_debug(1, "in png_handle_sPLT\n");

   if (!(png_ptr->mode & PNG_HAVE_IHDR))
      png_error(png_ptr, "Missing IHDR before sPLT");
   else if (png_ptr->mode & PNG_HAVE_IDAT)
   {
      png_warning(png_ptr, "Invalid sPLT after IDAT");
      png_crc_finish(png_ptr, length);
      return;
   }

#ifdef PNG_MAX_MALLOC_64K
   if (length > (png_uint_32)65535L)
   {
      png_warning(png_ptr, "sPLT chunk too large to fit in memory");
      skip = length - (png_uint_32)65535L;
      length = (png_uint_32)65535L;
   }
#endif

   chunkdata = (png_bytep)png_malloc(png_ptr, length + 1);
   slength = (png_size_t)length;
   png_crc_read(png_ptr, (png_bytep)chunkdata, slength);

   if (png_crc_finish(png_ptr, skip))
   {
      png_free(png_ptr, chunkdata);
      return;
   }

   chunkdata[slength] = 0x00;

   for (entry_start = chunkdata; *entry_start; entry_start++)
      /* empty loop to find end of name */ ;
   ++entry_start;

   /* a sample depth should follow the separator, and we should be on it  */
   if (entry_start > chunkdata + slength)
   {
      png_free(png_ptr, chunkdata);
      png_warning(png_ptr, "malformed sPLT chunk");
      return;
   }

   new_palette.depth = *entry_start++;
   entry_size = (new_palette.depth == 8 ? 6 : 10);
   data_length = (slength - (entry_start - chunkdata));

   /* integrity-check the data length */
   if (data_length % entry_size)
   {
      png_free(png_ptr, chunkdata);
      png_warning(png_ptr, "sPLT chunk has bad length");
      return;
   }

   new_palette.nentries = (png_uint_32) (data_length / entry_size);
   if ((png_uint_32) new_palette.nentries > (png_uint_32) (PNG_SIZE_MAX /
       png_sizeof(png_sPLT_entry)))
   {
       png_warning(png_ptr, "sPLT chunk too long");
       return;
   }
   new_palette.entries = (png_sPLT_entryp)png_malloc_warn(
       png_ptr, new_palette.nentries * png_sizeof(png_sPLT_entry));
   if (new_palette.entries == NULL)
   {
       png_warning(png_ptr, "sPLT chunk requires too much memory");
       return;
   }

#ifndef PNG_NO_POINTER_INDEXING
   for (i = 0; i < new_palette.nentries; i++)
   {
      png_sPLT_entryp pp = new_palette.entries + i;

      if (new_palette.depth == 8)
      {
          pp->red = *entry_start++;
          pp->green = *entry_start++;
          pp->blue = *entry_start++;
          pp->alpha = *entry_start++;
      }
      else
      {
          pp->red   = png_get_uint_16(entry_start); entry_start += 2;
          pp->green = png_get_uint_16(entry_start); entry_start += 2;
          pp->blue  = png_get_uint_16(entry_start); entry_start += 2;
          pp->alpha = png_get_uint_16(entry_start); entry_start += 2;
      }
      pp->frequency = png_get_uint_16(entry_start); entry_start += 2;
   }
#else
   pp = new_palette.entries;
   for (i = 0; i < new_palette.nentries; i++)
   {

      if (new_palette.depth == 8)
      {
          pp[i].red   = *entry_start++;
          pp[i].green = *entry_start++;
          pp[i].blue  = *entry_start++;
          pp[i].alpha = *entry_start++;
      }
      else
      {
          pp[i].red   = png_get_uint_16(entry_start); entry_start += 2;
          pp[i].green = png_get_uint_16(entry_start); entry_start += 2;
          pp[i].blue  = png_get_uint_16(entry_start); entry_start += 2;
          pp[i].alpha = png_get_uint_16(entry_start); entry_start += 2;
      }
      pp->frequency = png_get_uint_16(entry_start); entry_start += 2;
   }
#endif

   /* discard all chunk data except the name and stash that */
   new_palette.name = (png_charp)chunkdata;

   png_set_sPLT(png_ptr, info_ptr, &new_palette, 1);

   png_free(png_ptr, chunkdata);
   png_free(png_ptr, new_palette.entries);
}
