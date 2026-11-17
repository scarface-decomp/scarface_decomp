// bin: pc
// va: 0x006DDC80
// tool: the portal's starter code (no AI)
// core::ControllerDirectInput::vfunc_05 (0x006DDC80, 7 bytes)
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
    virtual void* vfunc_05();
    char m_pad04[0x140];
    int m_Field144; // +0x144
};

void* ControllerDirectInput::vfunc_05()
{
    return &m_Field144;
}

}
