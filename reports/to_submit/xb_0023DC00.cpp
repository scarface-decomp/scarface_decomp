// bin: xb
// va: 0x0023DC00
// what: 
// tool: the portal's starter code (no AI)

// sub_0023DC00 (0x0023DC00, 137 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field08
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
    virtual int vfunc_17();
};

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
    virtual int vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual int vfunc_25();
};

extern "C" char DAT_003D4440[];
extern "C" int __cdecl sub_00250E60(int, int);
extern "C" int __cdecl sub_00250E80(int, int);

class Class_0023DC00
{
public:
    Class_0023DC00* sub_0023DC00(int a1, int a2, int a3);
    void sub_0023D8A0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
};

Class_0023DC00* Class_0023DC00::sub_0023DC00(int a1, int a2, int a3)
{
    int r_edi, t4, t6;
    Field08* t5;
    Field08* t7;

    r_edi = 0;
    m_Field04 = 0;
    m_Field00 = (int)DAT_003D4440;
    m_Field08 = (Field08*)a1;
    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    m_Field0C = r_edi;
    m_Field10 = r_edi;
    m_Field14 = r_edi;
    m_Field18 = r_edi;
    m_Field1C = r_edi;
    m_Field20 = r_edi;
    m_Field28 = -1;
    r_edi = sub_00250E80(a2, 16);
    t4 = sub_00250E60(a3, m_Field08->vfunc_17());
    t5 = m_Field08;
    m_Field10 = r_edi;
    m_Field14 = t4;
    t6 = ((Object*)(int)t5)->vfunc_16();
    t7 = m_Field08;
    m_Field24 = t6;
    m_Field0C = ((Object*)(int)t7)->vfunc_25();
    sub_0023D8A0();
    return this;
}
