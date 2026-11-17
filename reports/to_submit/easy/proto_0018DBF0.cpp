// bin: proto
// va: 0x0018DBF0
// tool: the portal's starter code (no AI)
// TeleportHUD::vfunc_30 (0x0018DBF0, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field7C
{
    void sub_00023EB0(int);
};

class TeleportHUD
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
    virtual void vfunc_30(int a1);
    void sub_001819F0();
    void sub_001856F0();
    void sub_001B7A10();
    char m_pad04[0x44];
    int m_Field48; // +0x48
    char m_pad4C[0x18];
    int m_Field64; // +0x64
    char m_pad68[0x10];
    bool m_Field78; // +0x78
    char m_pad79[0x3];
    Field7C* m_Field7C; // +0x7C
};

void TeleportHUD::vfunc_30(int a1)
{
    int t3;

    if (m_Field7C) {
        m_Field7C->sub_00023EB0(0);
    }
    sub_001819F0();
    t3 = m_Field64;
    if (m_Field64) {
        if (*(int*)(t3 + 104)) goto L_50;
        if (*(bool*)(t3 + 208)) goto L_50;
        sub_001856F0();
        sub_001B7A10();
        if (!m_Field78) goto L_50;
        m_Field48 = 2;
        m_Field78 = false;
    }
L_50:
    ;
}
