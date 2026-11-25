// verify: python portal/verify.py reports/to_submit/xb_002C6B80.cpp --va 0x002C6B80 --bin xb --match '_crc32_little' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C6B80
// what: Updates a CRC-32 over a block of bytes four at a time, for little-endian machines (zlib 1.2.1's crc32_little).
// tool: Claude Fable 5.2 (the public zlib 1.2.1 source, unchanged; SPEC-014 section 5.3)
// zlib 1.2.1, Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler. The file is the published one.
#include "zlib-1.2.1/crc32.c"
