// bin: xb
// va: 0x0028D580
// tool: the portal's starter code (no AI)
// pure3d::frontend::Screen::vfunc_14 (0x0028D580, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d { namespace frontend {

class Screen
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
    virtual bool vfunc_14();
    char m_pad04[0x20];
    unsigned char m_Field24_bit0 : 1; // +0x24, bit 0
};

bool Screen::vfunc_14()
{
    return m_Field24_bit0;
}

} }
