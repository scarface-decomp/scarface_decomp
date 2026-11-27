// verify: python portal/verify.py reports/to_submit/xb_002CBA00.cpp --va 0x002CBA00 --bin xb --match '_png_handle_unknown' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002CBA00
// what: Reads a chunk libpng does not know: keeps it or passes it to the user's function, or skips it (libpng png_handle_unknown).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngrutil.c"
