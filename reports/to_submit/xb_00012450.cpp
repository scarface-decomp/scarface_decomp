// bin: xb
// va: 0x00012450
// what: Rotates a range of 16-byte records so the middle one becomes the first (standard library helper).
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_00012450.cpp --va 0x00012450 --bin xb --match '?$_Rotate@' --flags "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE"   (agent.py check cannot select a template instantiation; see the lane report)

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

// std::_Rotate for random-access iterators, instantiated for Class_00012450.
template void std::_Rotate<Class_00012450 *, int, Class_00012450>(Class_00012450 *, Class_00012450 *, Class_00012450 *, int *, Class_00012450 *);
