// bin: pc
// va: 0x006E74B0
// tool: the portal's starter code (no AI)
// core::Win32Drive::vfunc_12 (0x006E74B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F04C;

namespace core {

class Win32Drive
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12(int a1, int a2);
    char m_pad04[0xD8];
    int m_FieldDC; // +0xDC
};

int Win32Drive::vfunc_12(int a1, int a2)
{
    ((void (__stdcall*)(int))DAT_0072F04C)(a1);
    m_FieldDC += -1;
    return 1;
}

}
