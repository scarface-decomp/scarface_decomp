// bin: xb
// va: 0x0029FEA0
// tool: the portal's starter code (no AI)
// pure3d::d3dSimpleShader::vfunc_03 (0x0029FEA0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003D9D5C[];
extern "C" void __cdecl sub_00027600(int);

namespace pure3d {

class d3dSimpleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dSimpleShader* vfunc_03(int a1);
    void sub_0029A500();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

d3dSimpleShader* d3dSimpleShader::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field80;
    *(int*)this = (int)DAT_003D9D5C;
    if (m_Field80) {
        ((Object*)t1)->vfunc_01();
    }
    sub_0029A500();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}
