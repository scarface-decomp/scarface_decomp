// bin: proto
// va: 0x00171350
// tool: the portal's starter code (no AI)
// HUDBalls::vfunc_30 (0x00171350, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field44
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
    virtual bool vfunc_07();
};

struct Field78
{
    virtual void vfunc_00(int);
    virtual bool vfunc_01();
};

extern "C" void __stdcall sub_0021AF00(int);

class HUDBalls
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
    char m_pad04[0x38];
    unsigned char m_Field3C; // +0x3C
    char m_pad3D[0x7];
    Field44* m_Field44; // +0x44
    char m_pad48[0x30];
    Field78* m_Field78; // +0x78
    bool m_Field7C; // +0x7C
};

void HUDBalls::vfunc_30(int a1)
{
    if (m_Field3C & 1) {
        sub_0021AF00(a1);
        if (m_Field44->vfunc_07()) {
            m_Field44->vfunc_06(a1);
            goto L_2F;
        }
        m_Field3C &= 254;
    }
L_2F:
    vfunc_47();
    if (!m_Field7C) {
        if (m_Field78->vfunc_01()) goto L_54;
    }
    m_Field78->vfunc_00(a1);
L_54:
    ;
}
