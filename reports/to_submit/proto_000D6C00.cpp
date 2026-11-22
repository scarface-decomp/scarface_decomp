// bin: proto
// va: 0x000D6C00
// what: 
// tool: the portal's starter code (no AI)

// ExitConditionTrack::vfunc_17 (Proto 0x000D6C00, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;

class ExitConditionTrack
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
    virtual float vfunc_17();
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    char m_pad24[0x8];
    float m_Field2C; // +0x2C
};

float ExitConditionTrack::vfunc_17()
{
    if (m_Field1C > m_Field20) {
        return DAT_0037CE60;
    }
    if (m_Field2C > m_Field20) {
        return m_Field2C - m_Field1C;
    }
    return m_Field20 - m_Field1C;
}
