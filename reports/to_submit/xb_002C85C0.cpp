// verify: python portal/verify.py reports/to_submit/xb_002C85C0.cpp --va 0x002C85C0 --bin xb --match '_png_crc_read' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C85C0
// what: Reads chunk data and adds it to the running CRC (libpng png_crc_read).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrutil.c"
