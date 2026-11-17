// bin: xb
// va: 0x002C5670
// tool: the portal's starter code (no AI)
// pure3d::d3dDecalShader::vfunc_14 (0x002C5670, 88 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" bool DAT_004BD4B4;
extern "C" int sub_0033A678;
extern "C" int sub_0033A6AC;
extern "C" int sub_0033AA1C;
extern "C" void __stdcall sub_0029FEE0(int);

namespace pure3d {

class d3dDecalShader
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
    virtual void vfunc_14(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

void d3dDecalShader::vfunc_14(int a1)
{
    int t2;

    sub_0029FEE0(a1);
    if (m_Field18 == 1) {
        sub_0033A678 |= 1;
        sub_0033A6AC = 4;
    }
    if (DAT_004BD4B4) {
        t2 = sub_0033A678 | 12288;
        DAT_004BD4B4 = false;
        sub_0033A678 = t2;
        sub_0033AA1C = 0;
    }
}

}
