// bin: xb
// va: 0x001D7F40
// tool: the portal's starter code (no AI)
// SoundPoiObject::vfunc_04 (0x001D7F40, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0002B700(int);
extern "C" int __cdecl sub_0002B770(int, int);

class SoundPoiObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
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
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x14];
    int m_Field7C; // +0x7C
    char m_pad80[0x8];
    int m_Field88; // +0x88
};

void SoundPoiObject::vfunc_04(int a1)
{
    int t2;

    sub_0002B700(a1);
    t2 = m_Field88;
    if (m_Field88) {
        if (!*(unsigned char*)t2) goto L_2A;
        m_Field7C = sub_0002B770(t2, 0);
    }
L_2A:
    vfunc_29((int)(&m_Field64));
}
