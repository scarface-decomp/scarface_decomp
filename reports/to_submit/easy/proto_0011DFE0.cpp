// bin: proto
// va: 0x0011DFE0
// tool: the portal's starter code (no AI)
// BoatAIBehaviour::vfunc_36 (0x0011DFE0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00390010;

class BoatAIBehaviour
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
    virtual int vfunc_36();
    char m_pad04[0x24];
    float m_Field28; // +0x28
    char m_pad2C[0x48];
    bool m_Field74; // +0x74
    char m_pad75[0xF];
    int m_Field84; // +0x84
    char m_pad88[0xBC];
    int m_Field144; // +0x144
};

int BoatAIBehaviour::vfunc_36()
{
    float t1;

    t1 = DAT_00390010;
    m_Field74 = false;
    m_Field28 = t1;
    m_Field84 = 0;
    m_Field144 = 0;
    return 0;
}
