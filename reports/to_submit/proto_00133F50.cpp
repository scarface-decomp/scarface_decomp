// bin: proto
// va: 0x00133F50
// what: Passes a value stored in the object to another function and returns its result.
// tool: Claude Opus 5.5 (transplanted from xb:0x00211990, nearest by portal/tools/similar.py)

extern "C" void *__cdecl sub_00028120(int handle);

class Class_00133F50
{
public:
    void *sub_00133F50();

    char m_pad00[0xC0];
    int m_FieldC0; // +0xC0
};

// Looks the stored value up.
void *Class_00133F50::sub_00133F50()
{
    return sub_00028120(m_FieldC0);
}