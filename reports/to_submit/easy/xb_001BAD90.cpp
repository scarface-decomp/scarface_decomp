// bin: xb
// va: 0x001BAD90
// tool: the portal's starter code (no AI)
// PimpYourMansionHUD::vfunc_54 (0x001BAD90, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
};

struct Object2
{
    virtual void vfunc_00();
    virtual void vfunc_01(int, int);
};

extern "C" float DAT_003BAC90;
extern "C" void __stdcall sub_00193280(int);

class PimpYourMansionHUD
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
    char m_pad04[0x5C];
    unsigned char m_Field60; // +0x60
    char m_pad61[0xB];
    int m_Field6C; // +0x6C
    char m_pad70[0x4];
    int m_Field74; // +0x74
    char m_pad78[0x10];
    float m_Field88; // +0x88
};

void PimpYourMansionHUD::vfunc_54(int a1)
{
    int r_edi, t2, t4;

    if (m_Field60 & 1) {
        r_edi = a1;
        sub_00193280(a1);
        t2 = m_Field6C;
        if (m_Field6C) {
            ((Object*)t2)->vfunc_01(a1);
        }
        t4 = m_Field74;
        if (m_Field74) {
            ((Object2*)t4)->vfunc_01(r_edi, 0);
        }
        if (DAT_003BAC90 >= m_Field88) {
            m_Field88 = *(float*)(r_edi + 8) + m_Field88;
        }
    }
}
