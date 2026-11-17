// bin: pc
// va: 0x007013C0
// tool: the portal's starter code (no AI)
// movie::PlayerBink::vfunc_10 (0x007013C0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F2E0;

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
    virtual void vfunc_09();
    virtual int vfunc_10();
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int PlayerBink::vfunc_10()
{
    int r_eax;

    r_eax = m_Field18;
    if (r_eax == 4) {
        r_eax = m_Field1C;
        r_eax = ((int (__stdcall*)(int, int))DAT_0072F2E0)(r_eax, 1);
        m_Field18 = 3;
        return r_eax;
    }
    if (r_eax == 2) {
        m_Field18 = 1;
    }
    return r_eax;
}

}
