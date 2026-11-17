// bin: xb
// va: 0x00263FE0
// tool: the portal's starter code (no AI)
// pure3d::d3dExtTODFactor::vfunc_16 (0x00263FE0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" bool DAT_004BD4CC;

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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual bool vfunc_16(bool a1);
};

bool d3dExtTODFactor::vfunc_16(bool a1)
{
    DAT_004BD4CC = a1;
    return a1;
}

}
