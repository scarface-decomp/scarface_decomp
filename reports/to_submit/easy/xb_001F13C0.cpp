// bin: xb
// va: 0x001F13C0
// tool: the portal's starter code (no AI)
// MeleeWeaponStateProp::vfunc_29 (0x001F13C0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00089050(int);
};

class MeleeWeaponStateProp
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
    virtual void vfunc_29(int a1);
    char m_pad04[0x60];
    int m_Field64; // +0x64
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
    char m_pad70[0x58];
    int m_FieldC8; // +0xC8
};

void MeleeWeaponStateProp::vfunc_29(int a1)
{
    int t1;

    m_Field64 = *(int*)a1;
    m_Field68 = *(int*)(a1 + 4);
    m_Field6C = *(int*)(a1 + 8);
    t1 = m_FieldC8;
    if (m_FieldC8) {
        a1 = (int)this + 52;
        ((Object*)t1)->sub_00089050(a1);
        return;
    }
}
