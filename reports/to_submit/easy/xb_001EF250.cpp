// bin: xb
// va: 0x001EF250
// tool: the portal's starter code (no AI)
// sub_001EF250 (0x001EF250, 37 bytes)
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
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29(int);
};

class Class_001EF250
{
public:
    void sub_001EF250(int a1);
    char m_pad00[0x12A];
    unsigned char m_Field12A; // +0x12A
};

void Class_001EF250::sub_001EF250(int a1)
{
    if (a1) {
        if (m_Field12A & 64) goto L_21;
        ((Object*)a1)->vfunc_29((int)this);
        m_Field12A |= 64;
    }
L_21:
    ;
}
