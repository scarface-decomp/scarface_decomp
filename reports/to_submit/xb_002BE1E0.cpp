// verify: python portal/verify.py reports/to_submit/xb_002BE1E0.cpp --va 0x002BE1E0 --bin xb --match '_png_set_read_fn' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002BE1E0
// what: Sets the function and the pointer libpng reads the file with (libpng png_set_read_fn).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrio.c"
