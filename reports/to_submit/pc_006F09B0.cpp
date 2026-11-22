// bin: pc
// va: 0x006F09B0
// what: 
// tool: the portal's starter code (no AI)

// audio::StreamPlayerAllocator::vfunc_00 (PC 0x006F09B0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006F2080(int, int, int, int, int, int, int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual int vfunc_00(int a1, int a2, int a3, int a4, int a5, int a6);
};

int StreamPlayerAllocator::vfunc_00(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int t1;

    t1 = sub_006F2080(a4, 1, a3, a5, 0, 0, 1);
    *(int*)a6 = 0x20000;
    return t1;
}

}
