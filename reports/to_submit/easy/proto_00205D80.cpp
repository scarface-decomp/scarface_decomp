// bin: proto
// va: 0x00205D80
// tool: the portal's starter code (no AI)
// FEBoxObject::vfunc_34 (0x00205D80, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class FEBoxObject
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual unsigned short vfunc_34(int a1, int a2);
    char m_pad04[0x24];
    unsigned short m_Field28; // +0x28
    unsigned short m_Field2A; // +0x2A
};

unsigned short FEBoxObject::vfunc_34(int a1, int a2)
{
    unsigned short t1;

    *(unsigned short*)a1 = m_Field28;
    t1 = m_Field2A;
    *(unsigned short*)a2 = m_Field2A;
    return t1;
}
