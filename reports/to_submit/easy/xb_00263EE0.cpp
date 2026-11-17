// bin: xb
// va: 0x00263EE0
// tool: the portal's starter code (no AI)
// pure3d::d3dExtTODFactor::vfunc_05 (0x00263EE0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int DAT_0045C328;

namespace pure3d {

class d3dExtTODFactor
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
};

int d3dExtTODFactor::vfunc_05(int a1)
{
    DAT_0045C328 = a1;
    return a1;
}

}
