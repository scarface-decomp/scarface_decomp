// bin: xb
// va: 0x001FF3C0
// tool: the portal's starter code (no AI)
// WakeTemplate::vfunc_10 (0x001FF3C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class WakeTemplate
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
    virtual unsigned short vfunc_10();
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x5];
    unsigned short m_Field28; // +0x28
};

unsigned short WakeTemplate::vfunc_10()
{
    unsigned short t1;

    t1 = m_Field20;
    m_Field22 = true;
    m_Field28 = t1;
    return t1;
}
