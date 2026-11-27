// verify: python portal/verify.py reports/to_submit/xb_002C6B20.cpp --va 0x002C6B20 --bin xb --match '_png_free' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C6B20
// what: Frees memory through the user's free function or the default one; null is ignored (libpng png_free).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngmem.c"
