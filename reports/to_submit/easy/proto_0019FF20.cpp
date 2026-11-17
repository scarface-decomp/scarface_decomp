// bin: proto
// va: 0x0019FF20
// tool: the portal's starter code (no AI)
// SoundPoiObject::vfunc_05 (0x0019FF20, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00028C40(int);
extern "C" int __cdecl sub_00028CF0(int, int);

class SoundPoiObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
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
    virtual void vfunc_27(int);
    char m_pad04[0x5C];
    int m_Field60; // +0x60
    char m_pad64[0x1C];
    int m_Field80; // +0x80
    char m_pad84[0x8];
    int m_Field8C; // +0x8C
};

void SoundPoiObject::vfunc_05(int a1)
{
    int t2;

    sub_00028C40(a1);
    t2 = m_Field8C;
    if (m_Field8C) {
        if (!*(unsigned char*)t2) goto L_2D;
        m_Field80 = sub_00028CF0(t2, 0);
    }
L_2D:
    vfunc_27((int)(&m_Field60));
}
