// bin: pc
// va: 0x006E36A0
// tool: the portal's starter code (no AI)
// core::CompletionEventRequest::vfunc_01 (0x006E36A0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF0D0(int);

namespace core {

class CompletionEventRequest
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int CompletionEventRequest::vfunc_01()
{
    sub_006DF0D0(m_Field08);
    return 1;
}

}
