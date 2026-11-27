// verify: python portal/verify.py reports/to_submit/xb_002CA3C0.cpp --va 0x002CA3C0 --bin xb --match '_png_handle_sRGB' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002CA3C0
// what: Reads a PNG file's sRGB chunk, the sRGB rendering intent, checks it and stores it (libpng png_handle_sRGB).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrutil.c"
