// bin: pc
// va: 0x006E7490
// tool: the portal's starter code (no AI)
// core::Win32Drive::vfunc_01 (0x006E7490, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF070(int);

namespace core {

class Win32Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void Win32Drive::vfunc_01()
{
    sub_006DF070((int)this + 236);
}

}
