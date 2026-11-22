// bin: proto
// va: 0x002065D0
// what: Passes a value stored in the object to another function and returns its result.
// tool: Claude Opus 5.5 (transplanted from xb:0x00211990, nearest by portal/tools/similar.py)

extern "C" void *__cdecl sub_0020B670(int handle);

class Class_002065D0
{
public:
    void *sub_002065D0();

    char m_pad00[0x4];
    int m_Field04; // +0x4
};

// Looks the stored value up.
void *Class_002065D0::sub_002065D0()
{
    return sub_0020B670(m_Field04);
}