// bin: xb
// va: 0x002927B0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::ShadowSkin::vfunc_12 (0x002927B0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_002582F0(int);
};

namespace pure3d {

class ShadowSkin
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
    virtual void vfunc_12(int a1);
    char m_pad04[0x40];
    int m_Field44; // +0x44
};

void ShadowSkin::vfunc_12(int a1)
{
    ((Object*)*(int*)m_Field44)->sub_002582F0(a1);
}

}
