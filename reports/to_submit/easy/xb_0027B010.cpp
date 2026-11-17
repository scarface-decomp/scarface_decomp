// bin: xb
// va: 0x0027B010
// tool: the portal's starter code (no AI)
// pure3d::BillboardObject::vfunc_10 (0x0027B010, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
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
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int, int);
};

extern "C" int DAT_00492F04;

namespace pure3d {

class BillboardObject
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
    virtual void vfunc_10(int a1, int a2);
    void sub_0025A690(int, int);
    char m_pad04[0x40];
    int m_Field44; // +0x44
    char m_pad48[0x10];
    int m_Field58; // +0x58
};

void BillboardObject::vfunc_10(int a1, int a2)
{
    ((Object*)*(int*)DAT_00492F04)->vfunc_25(0, *(int*)m_Field44 + 56);
    *(int*)(*(int*)m_Field44 + 120) = m_Field58;
    sub_0025A690(a1, a2);
    *(int*)(*(int*)m_Field44 + 120) = 0x3F800000;
    ((Object*)*(int*)DAT_00492F04)->vfunc_18(0);
}

}
