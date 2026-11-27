// verify: python portal/verify.py reports/to_submit/xb_002C9220.cpp --va 0x002C9220 --bin xb --match '_png_read_filter_row' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C9220
// what: Undoes a row's filter (sub, up, average or Paeth) using the previous row (libpng png_read_filter_row).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrutil.c"
