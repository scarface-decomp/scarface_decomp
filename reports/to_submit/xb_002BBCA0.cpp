// verify: python portal/verify.py reports/to_submit/xb_002BBCA0.cpp --va 0x002BBCA0 --bin xb --match '_png_do_gamma' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002BBCA0
// what: Row transformation: gamma-corrects the samples through the lookup tables (libpng png_do_gamma).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrtran.c"
