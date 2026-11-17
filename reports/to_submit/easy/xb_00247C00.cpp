// bin: xb
// va: 0x00247C00
// tool: the portal's starter code (no AI)
// core::ControllerXBox::vfunc_04 (0x00247C00, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int ControllerXBox::vfunc_04()
{
    return m_Field08 != 0;
}

}
