// bin: xb
// va: 0x000C4740
// tool: the portal's starter code (no AI)
// sub_000C4740 (0x000C4740, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field38
{
    void sub_00098B90(int);
};

extern "C" int __cdecl sub_0002AC90(int);

class Class_000C4740
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
    virtual void vfunc_30(int, int);
    void sub_000C4740(int a1);
    char m_pad04[0x34];
    Field38 m_Field38; // +0x38
    char m_pad39[0xC];
    bool m_Field45; // +0x45
};

void Class_000C4740::sub_000C4740(int a1)
{
    if (m_Field45) {
        vfunc_30(a1, sub_0002AC90(*(int*)((char*)this + 0x38)));
        m_Field45 = false;
        m_Field38.sub_00098B90(0);
    }
}
