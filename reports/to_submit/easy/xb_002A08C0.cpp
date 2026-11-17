// bin: xb
// va: 0x002A08C0
// tool: the portal's starter code (no AI)
// pure3d::d3dExtXboxControl::vfunc_15 (0x002A08C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004BD4CD;
extern "C" bool DAT_004BD4D1;

namespace pure3d {

class d3dExtXboxControl
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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual bool vfunc_15();
};

bool d3dExtXboxControl::vfunc_15()
{
    DAT_004BD4CD = false;
    DAT_004BD4D1 = false;
    return false;
}

}
