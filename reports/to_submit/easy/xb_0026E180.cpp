// bin: xb
// va: 0x0026E180
// tool: the portal's starter code (no AI)
// pure3d::SpriteLoader::vfunc_03 (0x0026E180, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00(int);
    virtual void vfunc_01();
    void sub_00262260();
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D6EE4[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0023F7A0(int);

namespace pure3d {

class SpriteLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SpriteLoader* vfunc_03(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

SpriteLoader* SpriteLoader::vfunc_03(int a1)
{
    int t1, t3, t5;

    t1 = m_Field18;
    *(int*)this = (int)DAT_003D6EE4;
    ((Object*)t1)->vfunc_01();
    t3 = m_Field14;
    if (m_Field14) {
        ((Object*)t3)->vfunc_00(1);
    }
    t5 = m_Field1C;
    if (m_Field1C) {
        ((Object*)t5)->sub_00262260();
        sub_00027600(t5);
    }
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}
