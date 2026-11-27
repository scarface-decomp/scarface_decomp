// verify: python portal/verify.py reports/to_submit/xb_002BC740.cpp --va 0x002BC740 --bin xb --match '_png_build_gamma_table' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002BC740
// what: Builds the lookup tables for gamma correction, for 8-bit and for 16-bit samples (libpng png_build_gamma_table).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrtran.c"
