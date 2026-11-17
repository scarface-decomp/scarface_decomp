// bin: pc
// va: 0x006DDF50
// tool: the portal's starter code (no AI)
// core::ControllerDirectInput::vfunc_08 (0x006DDF50, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerDirectInput
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
    virtual int vfunc_08();
    char m_pad04[0x268];
    int m_Field26C; // +0x26C
};

int ControllerDirectInput::vfunc_08()
{
    return m_Field26C;
}

}
