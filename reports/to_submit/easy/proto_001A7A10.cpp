// bin: proto
// va: 0x001A7A10
// tool: the portal's starter code (no AI)
// GangNestSpawnObject::vfunc_30 (0x001A7A10, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A1D84[];
extern "C" void __cdecl sub_000658E0(int, int, int, int);
extern "C" int __cdecl sub_0008E650(int);
extern "C" int __cdecl sub_0008EC60(int);

class GangNestSpawnObject
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
    virtual void vfunc_30(int a1, int a2, int a3);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x3C];
    int m_Field50; // +0x50
    bool m_Field54; // +0x54
};

void GangNestSpawnObject::vfunc_30(int a1, int a2, int a3)
{
    int t2, t3;

    if (m_Field54) {
        if (m_Field50 < 0) goto L_41;
        t2 = m_Field10;
        t3 = sub_0008E650(0);
        sub_000658E0(3, (int)DAT_003A1D84, sub_0008EC60(t2), t3);
        m_Field50 = -1;
    }
L_41:
    ;
}
