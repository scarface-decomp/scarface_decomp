// verify: python portal/verify.py reports/to_submit/xb_002C6AC0.cpp --va 0x002C6AC0 --bin xb --match '_png_malloc' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C6AC0
// what: Allocates memory through the user's allocator or the default one; running out is a fatal error (libpng png_malloc).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngmem.c"
