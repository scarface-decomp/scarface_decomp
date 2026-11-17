// bin: xb
// va: 0x002A0900
// tool: the portal's starter code (no AI)
// pure3d::d3dExtXboxControl::vfunc_17 (0x002A0900, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004BD4CD;
extern "C" bool DAT_004BD4CE;
extern "C" bool DAT_004BD4CF;
extern "C" bool DAT_004BD4D0;

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
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual bool vfunc_17();
};

bool d3dExtXboxControl::vfunc_17()
{
    DAT_004BD4D0 = false;
    DAT_004BD4CD = false;
    DAT_004BD4CF = false;
    DAT_004BD4CE = false;
    return false;
}

}
