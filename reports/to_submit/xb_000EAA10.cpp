// bin: xb
// va: 0x000EAA10
// what: Picks a median-of-three (or of nine for large ranges) pivot among 4-byte elements with a caller-supplied ordering function (standard library sort helper).
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_000EAA10.cpp --va 0x000EAA10 --bin xb --match '?$_Median@'   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// The sorted elements are 4 bytes wide and handed to the ordering function by value; what they
// point to is not known yet.
class Class_000EAA10;

// Caller-supplied ordering: true when the first element goes before the second.
typedef bool (*Class_000EAA10Less)(Class_000EAA10 *, Class_000EAA10 *);

// std::_Median with a predicate (pivot selection of std::sort), instantiated for an array of Class_000EAA10 pointers.
template void std::_Median<Class_000EAA10 **, Class_000EAA10Less>(Class_000EAA10 **, Class_000EAA10 **, Class_000EAA10 **, Class_000EAA10Less);
