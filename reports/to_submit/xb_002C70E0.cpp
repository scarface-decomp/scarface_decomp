// verify: python portal/verify.py reports/to_submit/xb_002C70E0.cpp --va 0x002C70E0 --bin xb --match '_inflate' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C70E0
// what: Decompresses as much of a deflate, zlib or gzip stream as the buffers allow: the state machine at the heart of zlib 1.2.1 (inflate).
// tool: Claude Fable 5.2 (the public zlib 1.2.1 source, unchanged; SPEC-014 section 5.3)
// zlib 1.2.1, Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler. The file is the published one.
#include "zlib-1.2.1/inflate.c"
