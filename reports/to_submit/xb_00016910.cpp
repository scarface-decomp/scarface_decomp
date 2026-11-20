// bin: xb
// va: 0x00016910
// what: Sorts a heap of 16-byte records by their float key (standard library std::sort_heap).
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_00016910.cpp --va 0x00016910 --bin xb --match '?$sort_heap@'   (agent.py check cannot select a template instantiation; see the lane report)

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

// std::sort_heap, instantiated for Class_00012450.
template void std::sort_heap<Class_00012450 *>(Class_00012450 *, Class_00012450 *);
