// bin: xb
// va: 0x000E63A0
// tool: the portal's starter code (no AI)
// SoundCueAction::vfunc_12 (0x000E63A0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class SoundCueAction
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
    virtual bool vfunc_12(float a1);
    char m_pad04[0xC];
    float m_Field10; // +0x10
};

bool SoundCueAction::vfunc_12(float a1)
{
    m_Field10 = a1 + m_Field10;
    return true;
}
