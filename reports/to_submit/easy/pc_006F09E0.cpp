// bin: pc
// va: 0x006F09E0
// tool: the portal's starter code (no AI)
// audio::StreamPlayerAllocator::vfunc_01 (0x006F09E0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F21F0(int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
};

void StreamPlayerAllocator::vfunc_01(int a1, int a2)
{
    sub_006F21F0(a2);
}

}
