// bin: pc
// va: 0x006E0250
// tool: the portal's starter code (no AI)
// core::String::vfunc_08 (0x006E0250, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class String
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
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

int String::vfunc_08()
{
    if (((unsigned char)(((unsigned int)m_Field14) >> 31)) & 1) {
        return 0;
    }
    return m_Field10;
}

}
