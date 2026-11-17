// bin: proto
// va: 0x00148EA0
// tool: the portal's starter code (no AI)
// CharacterObject::vfunc_27 (0x00148EA0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BF5E0(int);
};

class CharacterObject
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
    virtual void vfunc_27(int a1);
    char m_pad04[0x5C];
    int m_Field60; // +0x60
    int m_Field64; // +0x64
    int m_Field68; // +0x68
    char m_pad6C[0x11C];
    int m_Field188; // +0x188
};

void CharacterObject::vfunc_27(int a1)
{
    int t1;

    m_Field60 = *(int*)a1;
    m_Field64 = *(int*)(a1 + 4);
    m_Field68 = *(int*)(a1 + 8);
    t1 = m_Field188;
    if (m_Field188) {
        a1 = a1;
        ((Object*)t1)->sub_000BF5E0(a1);
        return;
    }
}
