// bin: xb
// va: 0x000EAC60
// what: Sorts an array of 4-byte elements with a caller-supplied ordering function, the standard library's quicksort loop.
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_000EAC60.cpp --va 0x000EAC60 --bin xb --match '?$_Sort@'   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// The sorted elements are 4 bytes wide and handed to the ordering function by value; what they
// point to is not known yet.
class Class_000EAC60;

// Caller-supplied ordering: true when the first element goes before the second.
typedef bool (*Class_000EAC60Less)(Class_000EAC60 *, Class_000EAC60 *);

// std::_Sort with a predicate (introsort loop of std::sort), instantiated for an array of Class_000EAC60 pointers.
template void std::_Sort<Class_000EAC60 **, int, Class_000EAC60Less>(Class_000EAC60 **, Class_000EAC60 **, int, Class_000EAC60Less);
