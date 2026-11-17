// bin: xb
// va: 0x00263F60
// tool: the portal's starter code (no AI)
// pure3d::d3dExtTODFactor::vfunc_10 (0x00263F60, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" bool DAT_004BD4C1;

namespace pure3d {

class d3dExtTODFactor
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
    virtual bool vfunc_10(bool a1);
};

bool d3dExtTODFactor::vfunc_10(bool a1)
{
    DAT_004BD4C1 = a1;
    return a1;
}

}
