// bin: xb
// va: 0x001E01D0
// tool: the portal's starter code (no AI)
// GangSpawnObject::vfunc_41 (0x001E01D0, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0002A160(int);
};

class GangSpawnObject
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
    virtual void vfunc_41(int a1, int a2);
    char m_pad04[0x98];
    int m_Field9C; // +0x9C
    int m_FieldA0; // +0xA0
    char m_padA4[0x4];
    bool m_FieldA8; // +0xA8
    char m_padA9[0x3];
    int m_FieldAC; // +0xAC
};

void GangSpawnObject::vfunc_41(int a1, int a2)
{
    int r_eax;

    r_eax = a2;
    if (!a2) {
        m_Field9C -= 1;
    } else {
        if (r_eax != 1) goto L_29;
        m_FieldA0 -= 1;
    }
    ((Object*)a1)->sub_0002A160(0);
L_29:
    r_eax = m_Field9C;
    if (!r_eax) {
        r_eax = m_FieldA8;
        if (!((unsigned char)r_eax)) goto L_4E;
        m_FieldA8 = false;
        m_FieldAC = 3;
    }
L_4E:
    ;
}
