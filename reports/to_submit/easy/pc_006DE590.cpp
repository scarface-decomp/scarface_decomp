// bin: pc
// va: 0x006DE590
// tool: the portal's starter code (no AI)
// core::ControllerSystemDirectInput::vfunc_12 (0x006DE590, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerSystemDirectInput
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
    virtual int vfunc_12(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

int ControllerSystemDirectInput::vfunc_12(int a1)
{
    int r_eax;

    r_eax = m_Field20;
    if (r_eax == a1) {
        m_Field20 = 0;
    }
    return r_eax;
}

}
