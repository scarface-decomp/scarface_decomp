// bin: pc
// va: 0x006E3700
// tool: the portal's starter code (no AI)
// core::FileCompletionRequest::vfunc_01 (0x006E3700, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E6120(int);
};

namespace core {

class FileCompletionRequest
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int FileCompletionRequest::vfunc_01()
{
    ((Object*)*(int*)(m_Field0C + 12))->sub_006E6120((int)this);
    return 3;
}

}
