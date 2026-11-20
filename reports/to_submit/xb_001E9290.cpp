// bin: xb
// va: 0x001E9290
// what: Sorts an array of 4-byte elements with a caller-supplied ordering function, the standard library's quicksort loop.
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_001E9290.cpp --va 0x001E9290 --bin xb --match '?$_Sort@'   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// The sorted elements are 4 bytes wide and handed to the ordering function by value; what they
// point to is not known yet.
class Class_001E9290;

// Caller-supplied ordering: true when the first element goes before the second.
typedef bool (*Class_001E9290Less)(Class_001E9290 *, Class_001E9290 *);

// std::_Sort with a predicate (introsort loop of std::sort), instantiated for an array of Class_001E9290 pointers.
template void std::_Sort<Class_001E9290 **, int, Class_001E9290Less>(Class_001E9290 **, Class_001E9290 **, int, Class_001E9290Less);
