// bin: pc
// va: 0x006DF4C0
// tool: the portal's starter code (no AI)
// core::Platform::vfunc_04 (0x006DF4C0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F268;
extern "C" int DAT_0072F288;

namespace core {

class Platform
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    int m_Field04; // +0x04
};

int Platform::vfunc_04()
{
    int r_eax;

    r_eax = m_Field04;
    if (!r_eax) {
        r_eax = ((int (__cdecl*)(void))DAT_0072F288)();
        if (r_eax) goto L_17;
        return ((int (__cdecl*)(void))DAT_0072F268)();
    }
L_17:
    return r_eax;
}

}
