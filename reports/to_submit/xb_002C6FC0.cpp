// verify: python portal/verify.py reports/to_submit/xb_002C6FC0.cpp --va 0x002C6FC0 --bin xb --match '_updatewindow' --flags "/TC /O2 /Ot /Oy /G6 /Gd /Zp4"
// bin: xb
// va: 0x002C6FC0
// what: Copies the newest output into zlib's sliding window so later matches can reach back into it (zlib 1.2.1's updatewindow).
// tool: Claude Fable 5.2 (the public zlib 1.2.1 source, unchanged; SPEC-014 section 5.3)
// zlib 1.2.1, Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler. The file is the published one.
#include "zlib-1.2.1/inflate.c"
