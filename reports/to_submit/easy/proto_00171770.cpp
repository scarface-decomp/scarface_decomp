// bin: proto
// va: 0x00171770
// tool: the portal's starter code (no AI)
// HUDFrontMeter::vfunc_45 (0x00171770, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(float);
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
    virtual void vfunc_30(int);
};

extern "C" float DAT_0037CD94;

class HUDFrontMeter
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
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45(float a1, int a2);
    char m_pad04[0x38];
    unsigned char m_Field3C; // +0x3C
    char m_pad3D[0x7];
    int m_Field44; // +0x44
    char m_pad48[0x4];
    int m_Field4C; // +0x4C
};

void HUDFrontMeter::vfunc_45(float a1, int a2)
{
    int r_ecx;

    r_ecx = (int)this;
    r_ecx = m_Field4C;
    if (a1 >= DAT_0037CD94) {
        if (r_ecx) {
            ((Object*)r_ecx)->vfunc_30(255);
        }
        r_ecx = m_Field44;
        ((Object*)r_ecx)->vfunc_01(a1);
        m_Field3C |= 1;
        return;
    }
    if (r_ecx) {
        ((Object*)r_ecx)->vfunc_30(120);
    }
    r_ecx = m_Field44;
    ((Object*)r_ecx)->vfunc_01(0);
    m_Field3C |= 1;
}
