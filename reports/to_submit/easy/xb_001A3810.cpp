// bin: xb
// va: 0x001A3810
// tool: the portal's starter code (no AI)
// sub_001A3810 (0x001A3810, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field84
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int);
};

struct FieldBC
{
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
    virtual void vfunc_29(int);
};

extern "C" char DAT_003BDDE8[];
extern "C" void __cdecl sub_00080300(int);

class Class_001A3810
{
public:
    void sub_001A3810();
    char m_pad00[0x60];
    unsigned char m_Field60; // +0x60
    char m_pad61[0x23];
    Field84* m_Field84; // +0x84
    char m_pad88[0x34];
    FieldBC* m_FieldBC; // +0xBC
    char m_padC0[0xC];
    int m_FieldCC; // +0xCC
    char m_padD0[0x348];
    float m_Field418; // +0x418
};

void Class_001A3810::sub_001A3810()
{
    if (m_FieldCC) {
        m_Field84->vfunc_02(0);
        m_FieldBC->vfunc_29(0);
        m_Field60 = (unsigned char)(m_Field60 | 1);
        m_Field418 = 0.0f;
        m_FieldCC = 2;
        sub_00080300((int)DAT_003BDDE8);
    }
}
