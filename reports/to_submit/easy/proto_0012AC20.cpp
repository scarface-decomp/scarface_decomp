// bin: proto
// va: 0x0012AC20
// tool: the portal's starter code (no AI)
// CarAITask_TrafficCop::vfunc_28 (0x0012AC20, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CarAITask_TrafficCop
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
    char m_pad04[0x34];
    int m_Field38; // +0x38
    char m_pad3C[0x4];
    bool m_Field40; // +0x40
    char m_pad41[0x3];
    float m_Field44; // +0x44
};

void CarAITask_TrafficCop::vfunc_28()
{
    if (m_Field38 != 6) {
        m_Field38 = 0;
    }
    m_Field40 = false;
    m_Field44 = 0.0f;
}
