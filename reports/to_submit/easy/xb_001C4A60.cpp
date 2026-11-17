// bin: xb
// va: 0x001C4A60
// tool: the portal's starter code (no AI)
// GenericAnimation::vfunc_03 (0x001C4A60, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GenericAnimation
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
    char m_pad14[0x4];
    float m_Field18; // +0x18
};

void GenericAnimation::vfunc_03()
{
    int t1;

    t1 = m_Field10;
    m_Field18 = 0.0f;
    m_Field08 = t1;
    vfunc_04();
}
