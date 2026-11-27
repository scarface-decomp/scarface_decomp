// verify: python portal/verify.py reports/to_submit/xb_002BE180.cpp --va 0x002BE180 --bin xb --match '_png_read_data' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002BE180
// what: Reads bytes of the file through the read function the user set; none set is a fatal error (libpng png_read_data).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrio.c"
