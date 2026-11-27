// verify: python portal/verify.py reports/to_submit/xb_002B9900.cpp --va 0x002B9900 --bin xb --match '_png_destroy_read_struct' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002B9900
// what: Frees the read structure and both info structures, and clears the caller's pointers (libpng png_destroy_read_struct).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngread.c"
