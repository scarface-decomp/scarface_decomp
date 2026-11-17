// bin: xb
// va: 0x000E5280
// tool: the portal's starter code (no AI)
// LayeredAnimationAction::vfunc_04 (0x000E5280, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class LayeredAnimationAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
    char m_pad04[0xC];
    unsigned char m_Field10_bit0 : 1; // +0x10, bit 0
};

bool LayeredAnimationAction::vfunc_04()
{
    return m_Field10_bit0;
}
