// bin: xb
// va: 0x001DFCF0
// tool: the portal's starter code (no AI)
// GangNestSpawnObject::vfunc_32 (0x001DFCF0, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C7C34[];
extern "C" void __cdecl sub_0006FC30(int, int, int, int);
extern "C" int __cdecl sub_00099C10(int);
extern "C" int __cdecl sub_0009A220(int);

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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32(int a1, int a2, int a3);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x40];
    int m_Field54; // +0x54
    char m_pad58[0x8];
    unsigned char m_Field60; // +0x60
};

void GangNestSpawnObject::vfunc_32(int a1, int a2, int a3)
{
    unsigned char t1;
    int t2, t3;

    t1 = m_Field60;
    if (m_Field60 & 1) {
        if (m_Field54 < 0) goto L_51;
        if (!(t1 & 32)) goto L_51;
        if (!(t1 & 16)) {
            t2 = m_Field10;
            t3 = sub_00099C10(0);
            sub_0006FC30(3, (int)DAT_003C7C34, sub_0009A220(t2), t3);
            m_Field60 = (unsigned char)(m_Field60 | 16);
        }
        m_Field54 = -1;
    }
L_51:
    ;
}
