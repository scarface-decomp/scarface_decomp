// bin: xb
// va: 0x0007F600
// what: Sorts an array of 4-byte records by their unsigned key, the standard library's quicksort loop.
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_0007F600.cpp --va 0x0007F600 --bin xb --match '?$_Sort@'   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// A 4-byte record ordered by an unsigned key. Its operator< is defined in another file
// (sub_00242D50), so the sort calls it rather than inlining it.
class Class_0007F600
{
public:
    bool operator<(const Class_0007F600 &other) const;

    unsigned int m_Key;
};

// std::_Sort (introsort loop of std::sort), instantiated for Class_0007F600.
template void std::_Sort<Class_0007F600 *, int>(Class_0007F600 *, Class_0007F600 *, int);
