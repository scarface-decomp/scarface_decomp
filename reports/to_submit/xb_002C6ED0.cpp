// verify: python portal/verify.py reports/to_submit/xb_002C6ED0.cpp --va 0x002C6ED0 --bin xb --match '_inflateInit2_' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C6ED0
// what: Sets up a stream for decompression with a chosen window size, after checking the caller's zlib version (zlib 1.2.1's inflateInit2_).
// tool: Claude Fable 5.2 (the public zlib 1.2.1 source, unchanged; SPEC-014 section 5.3)
// zlib 1.2.1, Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler. The file is the published one.
#include "zlib-1.2.1/inflate.c"
