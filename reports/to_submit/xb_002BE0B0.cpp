// verify: python portal/verify.py reports/to_submit/xb_002BE0B0.cpp --va 0x002BE0B0 --bin xb --match '_png_do_bgr' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002BE0B0
// what: Row transformation: swaps red and blue (libpng png_do_bgr).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngtrans.c"
