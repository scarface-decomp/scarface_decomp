// bin: pc
// va: 0x006E51F0
// tool: the portal's starter code (no AI)
// core::File::vfunc_03 (0x006E51F0, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field12C
{
    void sub_005E1BB0();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_00772058[];
extern "C" char DAT_00772064[];
extern "C" char DAT_0085CDF8[];
extern "C" int DAT_0085CE10;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class File
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual File* vfunc_03(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    char m_pad10[0x11C];
    Field12C m_Field12C; // +0x12C
};

File* File::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_00772064;
    m_Field04 = (int)DAT_00772058;
    ((Object*)t1)->vfunc_01();
    m_Field12C.sub_005E1BB0();
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDF8);
        ((Object*)DAT_0085CE10)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDF8);
    }
    return this;
}

}
