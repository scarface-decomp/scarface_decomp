// verify: python portal/verify.py reports/to_submit/xb_002B8680.cpp --va 0x002B8680 --bin xb --match '_png_calculate_crc' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002B8680
// what: Adds a block of bytes to the running CRC of the chunk being read, unless the chunk's CRC is to be ignored (libpng png_calculate_crc).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/png.c"
