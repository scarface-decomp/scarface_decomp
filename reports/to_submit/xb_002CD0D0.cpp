// verify: python portal/verify.py reports/to_submit/xb_002CD0D0.cpp --va 0x002CD0D0 --bin xb --match '_png_set_cHRM_fixed' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002CD0D0
// what: Stores the chromaticities, as fixed-point numbers in the image's info structure (libpng png_set_cHRM_fixed).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngset.c"
