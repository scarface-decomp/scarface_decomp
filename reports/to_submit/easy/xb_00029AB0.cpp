// bin: xb
// va: 0x00029AB0
// tool: the portal's starter code (no AI)
// sub_00029AB0 (0x00029AB0, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_000999A0();
};

extern "C" char DAT_0039F52C[];

class Class_00029AB0
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
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30(int);
    void sub_00029AB0();
    void sub_00029F90();
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
    char m_pad31[0x7];
    short m_Field38; // +0x38
};

void Class_00029AB0::sub_00029AB0()
{
    *(int*)this = (int)DAT_0039F52C;
    if (m_Field38 > 0) {
        do {
            vfunc_30(*(int*)*(int*)((char*)this + 0x30));
        } while (m_Field38 > 0);
    }
    m_Field30.sub_000999A0();
    m_Field30.sub_000999A0();
    sub_00029F90();
}
