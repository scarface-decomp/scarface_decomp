// bin: proto
// va: 0x00264590
// tool: the portal's starter code (no AI)
// pure3d::d3dExtXboxControl::vfunc_10 (0x00264590, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0048E12D;
extern "C" bool DAT_0048E131;

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
    virtual bool vfunc_10();
};

bool d3dExtXboxControl::vfunc_10()
{
    DAT_0048E12D = false;
    DAT_0048E131 = false;
    return false;
}

}
