// bin: xb
// va: 0x00263DE0
// tool: the portal's starter code (no AI)
// pure3d::d3dExtTODFactor::vfunc_18 (0x00263DE0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int DAT_0045C350;
extern "C" int DAT_0045C354;
extern "C" int DAT_0045C358;

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
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual int vfunc_18(int a1, int a2, int a3);
};

int d3dExtTODFactor::vfunc_18(int a1, int a2, int a3)
{
    DAT_0045C350 = a1;
    DAT_0045C354 = a2;
    DAT_0045C358 = a3;
    return a1;
}

}
