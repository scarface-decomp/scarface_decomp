// bin: xb
// va: 0x000C4AC0
// what: Sorts an array of 4-byte elements with a caller-supplied ordering function, the standard library's quicksort loop.
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_000C4AC0.cpp --va 0x000C4AC0 --bin xb --match '?$_Sort@'   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// The sorted elements are 4 bytes wide and handed to the ordering function by value; what they
// point to is not known yet.
class Class_000C4AC0;

// Caller-supplied ordering: true when the first element goes before the second.
typedef bool (*Class_000C4AC0Less)(Class_000C4AC0 *, Class_000C4AC0 *);

// std::_Sort with a predicate (introsort loop of std::sort), instantiated for an array of Class_000C4AC0 pointers.
template void std::_Sort<Class_000C4AC0 **, int, Class_000C4AC0Less>(Class_000C4AC0 **, Class_000C4AC0 **, int, Class_000C4AC0Less);
