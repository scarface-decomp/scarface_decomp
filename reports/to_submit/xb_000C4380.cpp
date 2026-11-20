// bin: xb
// va: 0x000C4380
// what: Rotates a range of 4-byte elements so the middle one becomes the first (standard library helper).
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_000C4380.cpp --va 0x000C4380 --bin xb --match '?$_Rotate@' --flags "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE"   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// The rotated elements are 4 bytes wide; what they point to is not known yet.
class Class_000C4380;

// std::_Rotate for random-access iterators, instantiated for an array of Class_000C4380 pointers.
template void std::_Rotate<Class_000C4380 **, int, Class_000C4380 *>(Class_000C4380 **, Class_000C4380 **, Class_000C4380 **, int *, Class_000C4380 **);
