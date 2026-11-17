// bin: xb
// va: 0x00263ED0
// tool: the portal's starter code (no AI)
// pure3d::d3dExtTODFactor::vfunc_04 (0x00263ED0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int DAT_004BD4BC;

namespace pure3d {

class d3dExtTODFactor
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
};

int d3dExtTODFactor::vfunc_04(int a1)
{
    DAT_004BD4BC = a1;
    return a1;
}

}
