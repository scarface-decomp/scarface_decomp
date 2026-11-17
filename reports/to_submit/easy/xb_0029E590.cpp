// bin: xb
// va: 0x0029E590
// tool: the portal's starter code (no AI)
// pure3d::pddiDevice::vfunc_13 (0x0029E590, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int DAT_004BDC50;

namespace pure3d {

class pddiDevice
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
    virtual int vfunc_13(int a1);
};

int pddiDevice::vfunc_13(int a1)
{
    DAT_004BDC50 = a1;
    return a1;
}

}
