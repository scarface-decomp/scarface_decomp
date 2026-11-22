// bin: pc
// va: 0x006DF590
// what: 
// tool: the portal's starter code (no AI)

// core::Platform::vfunc_06 (PC 0x006DF590, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F28C;
extern "C" char sub_006DF530[];

namespace core {

class Platform
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int Platform::vfunc_06(int a1)
{
    int t1;

    if (!m_Field10) {
        t1 = m_Field04;
        if (!m_Field04) goto L_21;
        m_Field0C = ((int (__stdcall*)(int, int, int))DAT_0072F28C)(t1, -4, (int)sub_006DF530);
    }
L_21:
    *(int*)(a1 + 4) = m_Field10;
    m_Field10 = a1;
    return a1;
}

}
