// bin: pc
// va: 0x00706680
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dSpecularShader::vfunc_24 (PC 0x00706680, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007376F4[];
extern "C" char DAT_007680D8[];
extern "C" unsigned char DAT_00830A19;

namespace pure3d {

class d3dSpecularShader
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
};

int d3dSpecularShader::vfunc_24()
{
    int r_eax;

    r_eax = (int)DAT_007376F4;
    if (!DAT_00830A19) {
        r_eax = (int)DAT_007680D8;
    }
    return r_eax;
}

}
