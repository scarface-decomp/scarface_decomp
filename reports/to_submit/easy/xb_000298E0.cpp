// bin: xb
// va: 0x000298E0
// tool: the portal's starter code (no AI)
// FEGroupObject::vfunc_31 (0x000298E0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class FEGroupObject
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
    virtual void vfunc_31();
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x4];
    short m_Field38; // +0x38
};

void FEGroupObject::vfunc_31()
{
    if (m_Field38 > 0) {
        do {
            vfunc_30(*(int*)m_Field30);
        } while (m_Field38 > 0);
    }
}
