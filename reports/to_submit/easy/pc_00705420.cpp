// bin: pc
// va: 0x00705420
// tool: the portal's starter code (no AI)
// pure3d::d3dLayeredShader::vfunc_24 (0x00705420, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007680F0[];
extern "C" char DAT_007680FC[];

namespace pure3d {

class d3dLayeredShader
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
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual int vfunc_24();
    char m_pad04[0x44];
    unsigned char m_Field48; // +0x48
};

int d3dLayeredShader::vfunc_24()
{
    int r_eax;

    r_eax = (int)DAT_007680FC;
    if (m_Field48) {
        r_eax = (int)DAT_007680F0;
    }
    return r_eax;
}

}
