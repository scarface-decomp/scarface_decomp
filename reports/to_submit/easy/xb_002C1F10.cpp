// bin: xb
// va: 0x002C1F10
// tool: the portal's starter code (no AI)
// pure3d::d3dReflShader::vfunc_13 (0x002C1F10, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
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
    virtual void vfunc_18(int);
};

extern "C" bool DAT_004BD4B4;
extern "C" int sub_0033A678;
extern "C" int sub_0033A6D0;
extern "C" int sub_0033AA1C;

namespace pure3d {

class d3dReflShader
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
    char m_pad04[0xC];
    Field10* m_Field10; // +0x10
    int m_Field14; // +0x14
};

void d3dReflShader::vfunc_13()
{
    int t2, t3;

    m_Field10->vfunc_18(2);
    if (DAT_004BD4B4) {
        t2 = sub_0033A678 | 12288;
        DAT_004BD4B4 = false;
        sub_0033A678 = t2;
        sub_0033AA1C = 0;
    }
    t3 = m_Field14;
    if (*(int*)(m_Field14 + 228) != 1) {
        *(int*)(t3 + 228) = 1;
        sub_0033A678 |= 2048;
        sub_0033A6D0 = 1;
    }
}

}
