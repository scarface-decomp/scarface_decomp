// bin: pc
// va: 0x006E7480
// tool: the portal's starter code (no AI)
// core::Win32Drive::vfunc_00 (0x006E7480, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF080(int);

namespace core {

class Win32Drive
{
public:
    virtual void vfunc_00();
};

void Win32Drive::vfunc_00()
{
    sub_006DF080((int)this + 236);
}

}
