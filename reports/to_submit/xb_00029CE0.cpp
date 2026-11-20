// bin: xb
// va: 0x00029CE0
// what: Sorts a heap of 4-byte elements with a caller-supplied ordering function (standard library std::sort_heap).
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_00029CE0.cpp --va 0x00029CE0 --bin xb --match '?$sort_heap@'   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// The sorted elements are 4 bytes wide and handed to the ordering function by value; what they
// point to is not known yet.
class Class_00029D30;

// Caller-supplied ordering: true when the first element goes before the second.
typedef bool (*Class_00029D30Less)(Class_00029D30 *, Class_00029D30 *);

// std::sort_heap with a predicate, instantiated for an array of Class_00029D30 pointers.
template void std::sort_heap<Class_00029D30 **, Class_00029D30Less>(Class_00029D30 **, Class_00029D30 **, Class_00029D30Less);
