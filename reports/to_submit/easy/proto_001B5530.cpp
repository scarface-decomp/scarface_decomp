// bin: proto
// va: 0x001B5530
// tool: the portal's starter code (no AI)
// sub_001B5530 (0x001B5530, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27(int);
};

class Class_001B5530
{
public:
    void sub_001B5530(int a1);
    char m_pad00[0x112];
    unsigned char m_Field112; // +0x112
};

void Class_001B5530::sub_001B5530(int a1)
{
    if (a1) {
        if (m_Field112 & 64) goto L_21;
        ((Object*)a1)->vfunc_27((int)this);
        m_Field112 |= 64;
    }
L_21:
    ;
}
