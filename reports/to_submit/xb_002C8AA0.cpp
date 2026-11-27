// verify: python portal/verify.py reports/to_submit/xb_002C8AA0.cpp --va 0x002C8AA0 --bin xb --match '_png_combine_row' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C8AA0
// what: Copies the pixels of the row just read into the caller's row, all of them or those the mask selects (libpng png_combine_row).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrutil.c"
