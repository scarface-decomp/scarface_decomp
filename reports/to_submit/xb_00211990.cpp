// bin: xb
// va: 0x00211990
// what: Passes a value stored in the object to another function and returns its result.
// tool: Claude Opus 5.5 (symcov hint: TAIFollow::GetFollowCharacter)
// sub_00211990 (0x00211990, 16 bytes)

extern "C" void *__cdecl sub_0002AC90(int handle);

class Class_00211990
{
public:
    void *sub_00211990();

    char m_pad00[0x100];
    int m_Field100; // +0x100
};

// Looks the stored value up.
void *Class_00211990::sub_00211990()
{
    return sub_0002AC90(m_Field100);
}
