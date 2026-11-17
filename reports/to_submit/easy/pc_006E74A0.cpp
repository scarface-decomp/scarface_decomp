// bin: pc
// va: 0x006E74A0
// tool: the portal's starter code (no AI)
// core::Win32Drive::vfunc_05 (0x006E74A0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Win32Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
    char m_pad04[0xDC];
    int m_FieldE0; // +0xE0
};

void* Win32Drive::vfunc_05()
{
    return &m_FieldE0;
}

}
