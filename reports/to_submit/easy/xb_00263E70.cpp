// bin: xb
// va: 0x00263E70
// tool: the portal's starter code (no AI)
// pure3d::d3dExtTODFactor::vfunc_02 (0x00263E70, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int DAT_0045C314;
extern "C" int DAT_0045C318;
extern "C" int DAT_0045C31C;

namespace pure3d {

class d3dExtTODFactor
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1, int a2, int a3);
};

int d3dExtTODFactor::vfunc_02(int a1, int a2, int a3)
{
    DAT_0045C314 = a1;
    DAT_0045C318 = a2;
    DAT_0045C31C = a3;
    return a1;
}

}
