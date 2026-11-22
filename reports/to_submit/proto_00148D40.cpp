// bin: proto
// va: 0x00148D40
// what: Passes a value stored in the object to another function and returns its result.
// tool: Claude Opus 5.5 (transplanted from xb:0x00211990, nearest by portal/tools/similar.py)

extern "C" void *__cdecl sub_00028120(int handle);

class Class_00148D40
{
public:
    void *sub_00148D40();

    char m_pad00[0xD8];
    int m_FieldD8; // +0xD8
};

// Looks the stored value up.
void *Class_00148D40::sub_00148D40()
{
    return sub_00028120(m_FieldD8);
}