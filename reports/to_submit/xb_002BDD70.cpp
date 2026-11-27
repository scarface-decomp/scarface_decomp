// verify: python portal/verify.py reports/to_submit/xb_002BDD70.cpp --va 0x002BDD70 --bin xb --match '_png_do_invert' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002BDD70
// what: Row transformation: inverts grey samples (libpng png_do_invert).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngtrans.c"
