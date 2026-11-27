// verify: python portal/verify.py reports/to_submit/xb_002B9180.cpp --va 0x002B9180 --bin xb --match '_png_read_update_info' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002B9180
// what: Starts row reading if needed and updates the info structure for the transformations asked for (libpng png_read_update_info).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngread.c"
