// verify: python portal/verify.py reports/to_submit/xb_002BDE30.cpp --va 0x002BDE30 --bin xb --match '_png_do_packswap' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002BDE30
// what: Row transformation: reverses the order of the pixels packed in each byte (libpng png_do_packswap).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngtrans.c"
