// bin: proto
// va: 0x001D6820
// what: Passes a value stored in the object to another function and returns its result.
// tool: Claude Opus 5.5 (transplanted from xb:0x00211990, nearest by portal/tools/similar.py)

extern "C" void *__cdecl sub_00028120(int handle);

class Class_001D6820
{
public:
    void *sub_001D6820();

    char m_pad00[0xF4];
    int m_FieldF4; // +0xF4
};

// Looks the stored value up.
void *Class_001D6820::sub_001D6820()
{
    return sub_00028120(m_FieldF4);
}