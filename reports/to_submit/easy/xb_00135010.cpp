// bin: xb
// va: 0x00135010
// tool: the portal's starter code (no AI)
// AICommandMods::Mod_DestroyObject::vfunc_01 (0x00135010, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000F2AF0();
    int sub_001655C0();
};

namespace AICommandMods {

class Mod_DestroyObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void Mod_DestroyObject::vfunc_01(int a1, int a2)
{
    int t2;

    t2 = ((Object*)((Object*)a2)->sub_001655C0())->sub_000F2AF0();
    if (t2) {
        m_Field10 = *(int*)(t2 + 16);
        return;
    }
    m_Field10 = 0;
}

}
