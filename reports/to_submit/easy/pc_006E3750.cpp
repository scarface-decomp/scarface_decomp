// bin: pc
// va: 0x006E3750
// tool: the portal's starter code (no AI)
// core::FileCompletionRequest::vfunc_03 (0x006E3750, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class FileCompletionRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int FileCompletionRequest::vfunc_03()
{
    return *(int*)(m_Field0C + 12);
}

}
