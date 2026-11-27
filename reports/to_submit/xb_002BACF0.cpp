// verify: python portal/verify.py reports/to_submit/xb_002BACF0.cpp --va 0x002BACF0 --bin xb --match '_png_do_background' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002BACF0
// what: Row transformation: replaces transparency with the background colour, with gamma correction (libpng png_do_background).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrtran.c"
