// bin: xb
// va: 0x000C47B0
// what: Arranges an array of 4-byte elements into a heap with a caller-supplied ordering function (standard library helper).
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_000C47B0.cpp --va 0x000C47B0 --bin xb --match '?$_Make_heap@'   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// The sorted elements are 4 bytes wide and handed to the ordering function by value; what they
// point to is not known yet.
class Class_00029D30;

// Caller-supplied ordering: true when the first element goes before the second.
typedef bool (*Class_00029D30Less)(Class_00029D30 *, Class_00029D30 *);

// std::_Make_heap with a predicate, instantiated for an array of Class_00029D30 pointers.
template void std::_Make_heap<Class_00029D30 **, int, Class_00029D30 *, Class_00029D30Less>(Class_00029D30 **, Class_00029D30 **, Class_00029D30Less, int *, Class_00029D30 **);
