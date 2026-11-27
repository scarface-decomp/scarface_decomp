// verify: python portal/verify.py reports/to_submit/xb_002BA260.cpp --va 0x002BA260 --bin xb --match '_png_do_read_filler' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002BA260
// what: Row transformation: adds a filler byte to each pixel, before or after the colour (libpng png_do_read_filler).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrtran.c"
