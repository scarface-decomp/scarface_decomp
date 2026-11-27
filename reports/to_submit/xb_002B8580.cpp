// verify: python portal/verify.py reports/to_submit/xb_002B8580.cpp --va 0x002B8580 --bin xb --match '_png_sig_cmp' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002B8580
// what: Compares bytes with the 8-byte PNG signature; zero means they match (libpng png_sig_cmp).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/png.c"
