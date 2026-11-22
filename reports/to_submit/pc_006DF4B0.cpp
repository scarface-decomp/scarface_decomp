// bin: pc
// va: 0x006DF4B0
// what: 
// tool: the portal's starter code (no AI)

// core::Platform::vfunc_01 (PC 0x006DF4B0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Platform
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void Platform::vfunc_01()
{
    m_Field14 += -1;
}

}
