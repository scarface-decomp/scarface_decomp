// verify: python portal/verify.py reports/to_submit/xb_002CC370.cpp --va 0x002CC370 --bin xb --match '_zcfree' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002CC370
// what: Frees memory for zlib through the C library (zlib 1.2.1's zcfree).
// tool: Claude Fable 5.2 (the public zlib 1.2.1 source, unchanged; SPEC-014 section 5.3)
// zlib 1.2.1, Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler. The file is the published one.
#include "zlib-1.2.1/zutil.c"
