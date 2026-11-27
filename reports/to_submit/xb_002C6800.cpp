// verify: python portal/verify.py reports/to_submit/xb_002C6800.cpp --va 0x002C6800 --bin xb --match '_png_error' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C6800
// what: Reports a fatal error through the user's handler; if that returns, the default handler takes over (libpng png_error).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngerror.c"
