// bin: proto
// va: 0x000E1490
// what: Passes a value stored in the object to another function and returns its result.
// tool: Claude Opus 5.5 (transplanted from xb:0x00211990, nearest by portal/tools/similar.py)

extern "C" void *__cdecl sub_00028120(int handle);

class Class_000E1490
{
public:
    void *sub_000E1490();

    char m_pad00[0x2E0];
    int m_Field2E0; // +0x2E0
};

// Looks the stored value up.
void *Class_000E1490::sub_000E1490()
{
    return sub_00028120(m_Field2E0);
}