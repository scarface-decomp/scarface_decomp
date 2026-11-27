// verify: python portal/verify.py reports/to_submit/xb_002C9400.cpp --va 0x002C9400 --bin xb --match '_png_read_start_row' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C9400
// what: Sets up row reading: interlace pass sizes, the largest pixel depth needed, and the row buffers (libpng png_read_start_row).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrutil.c"
