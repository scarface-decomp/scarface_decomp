// bin: proto
// va: 0x00288730
// tool: the portal's starter code (no AI)
// pure3d::d3dDecalShader::vfunc_14 (0x00288730, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0048E880;
extern "C" int sub_00325508;
extern "C" int sub_0032553C;
extern "C" int sub_003258AC;
extern "C" void __stdcall sub_00263DF0(int);

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

    sub_00263DF0(a1);
    if (m_Field18 == 1) {
        sub_00325508 |= 1;
        sub_0032553C = 4;
    }
    if (DAT_0048E880) {
        t2 = sub_00325508 | 12288;
        DAT_0048E880 = false;
        sub_00325508 = t2;
        sub_003258AC = 0;
    }
}

}
