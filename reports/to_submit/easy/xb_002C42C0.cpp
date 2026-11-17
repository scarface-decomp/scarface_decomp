// bin: xb
// va: 0x002C42C0
// tool: the portal's starter code (no AI)
// pure3d::d3dSimpleCBVLitShader::vfunc_13 (0x002C42C0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int sub_0033A678;
extern "C" int sub_0033A6AC;
extern "C" void __cdecl sub_002A9290(void);

namespace pure3d {

class d3dSimpleCBVLitShader
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
    virtual int vfunc_13();
    char m_pad04[0x14];
    int m_Field18; // +0x18
    char m_pad1C[0xC];
    unsigned char m_Field28; // +0x28
};

int d3dSimpleCBVLitShader::vfunc_13()
{
    int r_eax;

    sub_002A9290();
    r_eax = 1;
    if (m_Field18 != 1) {
        if (m_Field28 != 1) goto L_29;
    }
    sub_0033A678 |= r_eax;
    sub_0033A6AC = 0;
L_29:
    return r_eax;
}

}
