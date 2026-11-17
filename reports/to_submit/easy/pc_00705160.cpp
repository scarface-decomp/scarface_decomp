// bin: pc
// va: 0x00705160
// tool: the portal's starter code (no AI)
// pure3d::d3dPointSpriteShader::vfunc_03 (0x00705160, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00774AAC[];
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dPointSpriteShader* vfunc_03(int a1);
    void sub_006527F0();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

d3dPointSpriteShader* d3dPointSpriteShader::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field80;
    *(int*)this = (int)DAT_00774AAC;
    if (m_Field80) {
        ((Object*)t1)->vfunc_01();
    }
    sub_006527F0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}
