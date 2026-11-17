// bin: pc
// va: 0x00701360
// tool: the portal's starter code (no AI)
// movie::PlayerBink::vfunc_08 (0x00701360, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F2FC;

namespace movie {

class PlayerBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

void PlayerBink::vfunc_08()
{
    if (m_Field18) {
        ((void (__stdcall*)(int))DAT_0072F2FC)(m_Field1C);
        m_Field1C = 0;
        m_Field18 = 0;
    }
}

}
