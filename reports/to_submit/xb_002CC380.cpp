// verify: python portal/verify.py reports/to_submit/xb_002CC380.cpp --va 0x002CC380 --bin xb --match '_inflate_fast' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002CC380
// what: Decodes literals and matches quickly while there is plenty of input and output room (zlib 1.2.1's inflate_fast).
// tool: Claude Fable 5.2 (the public zlib 1.2.1 source, unchanged; SPEC-014 section 5.3)
// zlib 1.2.1, Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler. The file is the published one.
#include "zlib-1.2.1/inffast.c"
