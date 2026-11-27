// verify: python portal/verify.py reports/to_submit/xb_002B8B00.cpp --va 0x002B8B00 --bin xb --match '_png_handle_as_unknown' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002B8B00
// what: Says how a chunk name is to be treated according to the list of chunks the user asked to keep (libpng png_handle_as_unknown).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/png.c"
