// bin: proto
// va: 0x001B8F50
// what: Passes a value stored in the object to another function and returns its result.
// tool: Claude Opus 5.5 (transplanted from xb:0x00211990, nearest by portal/tools/similar.py)

extern "C" void *__cdecl sub_00028120(int handle);

class Class_001B8F50
{
public:
    void *sub_001B8F50();

    char m_pad00[0x13C];
    int m_Field13C; // +0x13C
};

// Looks the stored value up.
void *Class_001B8F50::sub_001B8F50()
{
    return sub_00028120(m_Field13C);
}