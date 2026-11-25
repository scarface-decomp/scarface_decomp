// verify: python portal/verify.py reports/to_submit/xb_002CC7F0.cpp --va 0x002CC7F0 --bin xb --match '_inflate_table' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002CC7F0
// what: Builds a Huffman decoding table from a list of code lengths (zlib 1.2.1's inflate_table).
// tool: Claude Fable 5.2 (the public zlib 1.2.1 source, unchanged; SPEC-014 section 5.3)
// zlib 1.2.1, Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler. The file is the published one.
#include "zlib-1.2.1/inftrees.c"
