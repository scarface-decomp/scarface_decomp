// verify: python portal/verify.py reports/to_submit/xb_002CCE10.cpp --va 0x002CCE10 --bin xb --match '_png_set_cHRM' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002CCE10
// what: Stores the chromaticities (white point and primaries) in the image's info structure (libpng png_set_cHRM).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngset.c"
