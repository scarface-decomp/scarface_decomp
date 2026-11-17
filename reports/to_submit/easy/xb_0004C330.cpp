// bin: xb
// va: 0x0004C330
// tool: the portal's starter code (no AI)
// sub_0004C330 (0x0004C330, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
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
    virtual void vfunc_22(int);
};

extern "C" int DAT_00492EFC;

class Class_0004C330
{
public:
    void sub_0004C330(int a1);
    char m_pad00[0x40];
    unsigned char m_Field40; // +0x40
};

void Class_0004C330::sub_0004C330(int a1)
{
    if (m_Field40 != ((unsigned char)a1)) {
        ((Object*)DAT_00492EFC)->vfunc_22(a1);
        m_Field40 = (unsigned char)a1;
    }
}
