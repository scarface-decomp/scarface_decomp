// verify: python portal/verify.py reports/to_submit/xb_002B8B70.cpp --va 0x002B8B70 --bin xb --match '_png_create_info_struct' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002B8B70
// what: Allocates and clears the info structure that holds what is known about an image (libpng png_create_info_struct).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/png.c"
