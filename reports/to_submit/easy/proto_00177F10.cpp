// bin: proto
// va: 0x00177F10
// tool: the portal's starter code (no AI)
// HUDTrackable::vfunc_30 (0x00177F10, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field58
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
    virtual bool vfunc_02();
};

extern "C" void __stdcall sub_0021AF00(int);

class HUDTrackable
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
    virtual void vfunc_30(int a1);
    char m_pad04[0x38];
    unsigned char m_Field3C; // +0x3C
    char m_pad3D[0x1B];
    Field58* m_Field58; // +0x58
};

void HUDTrackable::vfunc_30(int a1)
{
    if (m_Field3C & 1) {
        sub_0021AF00(a1);
        if (m_Field58->vfunc_02()) {
            m_Field58->vfunc_01(a1);
            return;
        }
        m_Field3C &= 254;
    }
}
