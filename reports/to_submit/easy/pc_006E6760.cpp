// bin: pc
// va: 0x006E6760
// tool: the portal's starter code (no AI)
// core::CementLibrary::vfunc_07 (0x006E6760, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

int CementLibrary::vfunc_07()
{
    return m_Field20 == 1;
}

}
