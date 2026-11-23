// bin: xb
// va: 0x00263EA0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dExtTODFactor::vfunc_03 (0x00263EA0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int DAT_0045C320;
extern "C" int DAT_0045C324;
extern "C" int DAT_004BD4B8;

namespace pure3d {

class d3dExtTODFactor
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2, int a3);
};

int d3dExtTODFactor::vfunc_03(int a1, int a2, int a3)
{
    DAT_0045C320 = a1;
    DAT_0045C324 = a2;
    DAT_004BD4B8 = a3;
    return a1;
}

}
