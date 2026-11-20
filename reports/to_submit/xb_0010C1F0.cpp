// bin: xb
// va: 0x0010C1F0
// what: Rotates a range of 8-byte records so the middle one becomes the first (standard library helper).
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_0010C1F0.cpp --va 0x0010C1F0 --bin xb --match '?$_Rotate@' --flags "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE"   (agent.py check cannot select a template instantiation; see the lane report)

#include <algorithm>

// An 8-byte record; its fields are not known yet.
struct Class_0010C1F0
{
    int m_Field00;
    int m_Field04;
};

// std::_Rotate for random-access iterators, instantiated for Class_0010C1F0.
template void std::_Rotate<Class_0010C1F0 *, int, Class_0010C1F0>(Class_0010C1F0 *, Class_0010C1F0 *, Class_0010C1F0 *, int *, Class_0010C1F0 *);
