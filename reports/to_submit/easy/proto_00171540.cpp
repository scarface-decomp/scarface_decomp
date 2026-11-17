// bin: proto
// va: 0x00171540
// tool: the portal's starter code (no AI)
// HUDHeatMeter::vfunc_38 (0x00171540, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_00170F00(int);

class HUDHeatMeter
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
    virtual bool vfunc_38(int a1);
    char m_pad04[0x38];
    unsigned char m_Field3C; // +0x3C
    char m_pad3D[0x3B];
    float m_Field78; // +0x78
};

bool HUDHeatMeter::vfunc_38(int a1)
{
    if (sub_00170F00(0)) {
        return true;
    }
    m_Field3C = (unsigned char)(m_Field3C & 254);
    m_Field78 = 0.0f;
    return false;
}
