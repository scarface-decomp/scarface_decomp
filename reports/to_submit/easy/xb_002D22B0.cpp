// bin: xb
// va: 0x002D22B0
// tool: the portal's starter code (no AI)
// audio::StreamPlayerAllocator::vfunc_00 (0x002D22B0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_00020000[];
extern "C" int __cdecl sub_002D41D0(int, int, int, int, int, int, int);

namespace audio {

class StreamPlayerAllocator
{
public:
    virtual int vfunc_00(int a1, int a2, int a3, int a4, int a5, int a6);
};

int StreamPlayerAllocator::vfunc_00(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int t1;

    t1 = sub_002D41D0(a4, 1, a3, a5, 0, 0, 1);
    *(int*)a6 = (int)sub_00020000;
    return t1;
}

}
