// bin: xb
// va: 0x00029D30
// what: Sorts an array of 4-byte elements with a caller-supplied ordering function, the standard library's quicksort loop.
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_00029D30.cpp --va 0x00029D30 --bin xb --match '?$_Sort@'   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// The sorted elements are 4 bytes wide and handed to the ordering function by value; what they
// point to is not known yet.
class Class_00029D30;

// Caller-supplied ordering: true when the first element goes before the second.
typedef bool (*Class_00029D30Less)(Class_00029D30 *, Class_00029D30 *);

// std::_Sort with a predicate (introsort loop of std::sort), instantiated for an array of Class_00029D30 pointers.
template void std::_Sort<Class_00029D30 **, int, Class_00029D30Less>(Class_00029D30 **, Class_00029D30 **, int, Class_00029D30Less);
