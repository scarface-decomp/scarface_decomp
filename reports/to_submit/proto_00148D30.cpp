// bin: proto
// va: 0x00148D30
// what: Passes a value stored in the object to another function and returns its result.
// tool: Claude Opus 5.5 (transplanted from xb:0x00211990, nearest by portal/tools/similar.py)

extern "C" void *__cdecl sub_00028120(int handle);

class Class_00148D30
{
public:
    void *sub_00148D30();

    char m_pad00[0xDC];
    int m_FieldDC; // +0xDC
};

// Looks the stored value up.
void *Class_00148D30::sub_00148D30()
{
    return sub_00028120(m_FieldDC);
}