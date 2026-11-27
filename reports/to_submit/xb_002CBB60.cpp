// verify: python portal/verify.py reports/to_submit/xb_002CBB60.cpp --va 0x002CBB60 --bin xb --match '_png_read_finish_row' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002CBB60
// what: Moves to the next row or interlace pass; after the last row it reads to the end of the image data (libpng png_read_finish_row).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrutil.c"
