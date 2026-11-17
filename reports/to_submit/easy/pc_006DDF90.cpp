// bin: pc
// va: 0x006DDF90
// tool: the portal's starter code (no AI)
// core::ControllerDirectInput::vfunc_13 (0x006DDF90, 7 bytes)
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
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual int vfunc_13();
    char m_pad04[0x274];
    int m_Field278; // +0x278
};

int ControllerDirectInput::vfunc_13()
{
    return m_Field278;
}

}
