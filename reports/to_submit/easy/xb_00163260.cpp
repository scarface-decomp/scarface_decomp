// bin: xb
// va: 0x00163260
// tool: the portal's starter code (no AI)
// CharacterObject::vfunc_42 (0x00163260, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000CF500(int);
};

extern "C" int DAT_0048A9D8;
extern "C" void __stdcall sub_000CF480(int);

class CharacterObject
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
    virtual void vfunc_42(int a1);
    char m_pad04[0x1A8];
    int m_Field1AC; // +0x1AC
};

void CharacterObject::vfunc_42(int a1)
{
    int r_ebx, t1, t2;

    t1 = m_Field1AC;
    if (!m_Field1AC) goto L_38;
    r_ebx = a1;
    t2 = DAT_0048A9D8;
    if (DAT_0048A9D8) {
        if ((int)this != t2) goto L_31;
        if ((unsigned char)a1) goto L_31;
        a1 = 0;
        ((Object*)t1)->sub_000CF500(a1);
        return;
    }
L_31:
    sub_000CF480(r_ebx);
L_38:
    ;
}
