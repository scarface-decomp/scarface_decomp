// bin: proto
// va: 0x001B90A0
// what: Passes a value stored in the object to another function and returns its result.
// tool: Claude Opus 5.5 (transplanted from xb:0x00211990, nearest by portal/tools/similar.py)

extern "C" void *__cdecl sub_00028120(int handle);

class Class_001B90A0
{
public:
    void *sub_001B90A0();

    char m_pad00[0x130];
    int m_Field130; // +0x130
};

// Looks the stored value up.
void *Class_001B90A0::sub_001B90A0()
{
    return sub_00028120(m_Field130);
}