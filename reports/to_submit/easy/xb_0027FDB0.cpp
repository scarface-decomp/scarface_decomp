// bin: xb
// va: 0x0027FDB0
// tool: the portal's starter code (no AI)
// pure3d::TextureLoader::vfunc_03 (0x0027FDB0, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00(int);
    void sub_00262260();
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D7CAC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0023F7A0(int);

namespace pure3d {

class TextureLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TextureLoader* vfunc_03(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

TextureLoader* TextureLoader::vfunc_03(int a1)
{
    int t1, t4;

    t1 = m_Field14;
    *(int*)this = (int)DAT_003D7CAC;
    if (m_Field14) {
        ((Object*)t1)->sub_00262260();
        sub_00027600(t1);
    }
    t4 = m_Field18;
    if (m_Field18) {
        ((Object*)t4)->vfunc_00(1);
    }
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}
