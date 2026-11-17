// bin: pc
// va: 0x006EAC60
// tool: the portal's starter code (no AI)
// content::LoadStream::vfunc_03 (0x006EAC60, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_0077240C[];
extern "C" void __cdecl sub_006DC500(int);
extern "C" void __cdecl sub_006E9810(int);
extern "C" void __cdecl sub_006EA9E0(void);

namespace content {

class LoadStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadStream* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x18];
    int m_Field24; // +0x24
};

LoadStream* LoadStream::vfunc_03(int a1)
{
    int t2, t4;

    *(int*)this = (int)DAT_0077240C;
    sub_006EA9E0();
    t2 = m_Field08;
    if (m_Field08) {
        ((Object*)t2)->vfunc_01();
    }
    t4 = m_Field24;
    if (m_Field24) {
        sub_006DC500(t4);
    }
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006E9810((int)this);
    }
    return this;
}

}
