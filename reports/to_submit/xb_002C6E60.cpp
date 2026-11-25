// verify: python portal/verify.py reports/to_submit/xb_002C6E60.cpp --va 0x002C6E60 --bin xb --match '_crc32' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C6E60
// what: Updates a running CRC-32 checksum with a block of bytes (zlib 1.2.1's crc32); it hands the work to the little-endian routine.
// tool: Claude Fable 5.2 (the public zlib 1.2.1 source, unchanged; SPEC-014 section 5.3)
// zlib 1.2.1, Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler. The file is the published one.
#include "zlib-1.2.1/crc32.c"
