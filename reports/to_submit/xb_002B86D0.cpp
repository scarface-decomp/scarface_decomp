// verify: python portal/verify.py reports/to_submit/xb_002B86D0.cpp --va 0x002B86D0 --bin xb --match '_png_free_data' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002B86D0
// what: Frees the parts of an info structure the mask names (text, palette, profile, rows and so on) (libpng png_free_data).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/png.c"
