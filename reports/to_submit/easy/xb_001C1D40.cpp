// bin: xb
// va: 0x001C1D40
// tool: the portal's starter code (no AI)
// TeleportHUD::vfunc_54 (0x001C1D40, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field8C
{
    bool sub_001A62C0(int);
};

struct FieldA4
{
    void sub_000260C0(int);
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54(int a1);
    void sub_001ADF50();
    void sub_001AF950();
    char m_pad04[0x6C];
    int m_Field70; // +0x70
    char m_pad74[0x18];
    Field8C* m_Field8C; // +0x8C
    char m_pad90[0x10];
    bool m_FieldA0; // +0xA0
    char m_padA1[0x3];
    FieldA4* m_FieldA4; // +0xA4
};

void TeleportHUD::vfunc_54(int a1)
{
    if (m_FieldA4) {
        m_FieldA4->sub_000260C0(0);
    }
    sub_001ADF50();
    if (m_Field8C) {
        if (m_Field8C->sub_001A62C0(0)) goto L_4F;
        sub_001AF950();
        if (!m_FieldA0) goto L_4F;
        m_Field70 = 2;
        m_FieldA0 = false;
    }
L_4F:
    ;
}
