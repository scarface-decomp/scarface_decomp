// bin: pc
// va: 0x006E6770
// tool: the portal's starter code (no AI)
// core::CementLibrary::vfunc_06 (0x006E6770, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

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
    virtual void vfunc_06(int a1, int a2);
    char m_pad04[0x68];
    int m_Field6C; // +0x6C
    int m_Field70; // +0x70
};

void CementLibrary::vfunc_06(int a1, int a2)
{
    m_Field6C = a1;
    m_Field70 = a2;
    ((Object*)a1)->vfunc_00();
}

}
