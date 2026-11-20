// bin: xb
// va: 0x00014FC0
// what: Picks a median-of-three (or of nine for large ranges) pivot among 16-byte records ordered by their float key (standard library sort helper).
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_00014FC0.cpp --va 0x00014FC0 --bin xb --match '?$_Median@'   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// A 16-byte record sorted by its leading float key; the other fields are not known yet.
struct Class_00012450
{
    float m_Key;
    int m_Field04;
    int m_Field08;
    int m_Field0C;
};

// Records order by their key.
inline bool operator<(const Class_00012450 &left, const Class_00012450 &right)
{
    return left.m_Key < right.m_Key;
}

// std::_Median (pivot selection of std::sort), instantiated for Class_00012450.
template void std::_Median<Class_00012450 *>(Class_00012450 *, Class_00012450 *, Class_00012450 *);
