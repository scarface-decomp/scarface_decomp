// verify: python portal/verify.py reports/to_submit/xb_002C6950.cpp --va 0x002C6950 --bin xb --match '_png_create_struct_2' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C6950
// what: Allocates and clears a png or info structure by type, through the user's allocator if one is given (libpng png_create_struct_2).
// tool: Claude Fable 5.2 (the public libpng 1.2.8 source, unchanged; SPEC-014 section 5)
// libpng 1.2.8, Copyright (c) 1998-2004 Glenn Randers-Pehrson and others. The file is the published one.
#include "libpng-1.2.8/pngmem.c"
