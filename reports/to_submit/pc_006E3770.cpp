// bin: pc
// va: 0x006E3770
// what: 
// tool: the portal's starter code (no AI)

// core::FileRequest::vfunc_02 (PC 0x006E3770, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class FileRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int FileRequest::vfunc_02(int a1)
{
    return a1 == m_Field08;
}

}
