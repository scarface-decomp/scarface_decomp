// bin: xb
// va: 0x001908A0
// tool: the portal's starter code (no AI)
// BusinessDetailHUD::vfunc_32 (0x001908A0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001C4500(int);
};

extern "C" int DAT_0048E54C;
extern "C" void __stdcall sub_00193200(int);

class BusinessDetailHUD
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
    virtual void vfunc_32(int a1);
    void sub_001AF5C0();
    char m_pad04[0x5C];
    unsigned char m_Field60; // +0x60
    char m_pad61[0x9];
    bool m_Field6A; // +0x6A
};

void BusinessDetailHUD::vfunc_32(int a1)
{
    int r_eax;

    if (m_Field60 & 1) {
        r_eax = a1;
        sub_00193200(a1);
        r_eax = m_Field6A;
        if (!((unsigned char)r_eax)) goto L_44;
        r_eax = ((Object*)DAT_0048E54C)->sub_001C4500(0);
        if (r_eax == 2) {
            sub_001AF5C0();
            m_Field6A = false;
            return;
        }
        if (r_eax != 4) goto L_44;
        m_Field6A = false;
    }
L_44:
    ;
}
