// bin: xb
// va: 0x001A6290
// tool: the portal's starter code (no AI)
// sub_001A6290 (0x001A6290, 46 bytes)
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
    virtual void vfunc_17(int);
};

extern "C" char DAT_003BE6B8[];
extern "C" int __cdecl sub_00023EC0(int);

class Class_001A6290
{
public:
    void sub_001A6290(int a1);
    char m_pad00[0x9C];
    int m_Field9C; // +0x9C
    char m_padA0[0xC2];
    bool m_Field162; // +0x162
};

void Class_001A6290::sub_001A6290(int a1)
{
    int t2;

    if (m_Field9C == 1) {
        if (!m_Field162) goto L_2B;
        t2 = sub_00023EC0((int)DAT_003BE6B8);
        if (!t2) goto L_2B;
        ((Object*)t2)->vfunc_17(a1);
        return;
    }
L_2B:
    ;
}
