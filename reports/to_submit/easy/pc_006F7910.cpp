// bin: pc
// va: 0x006F7910
// tool: the portal's starter code (no AI)
// audio::SeqActionWait::vfunc_03 (0x006F7910, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
};

void SeqActionWait::vfunc_03(int a1)
{
    sub_006F57A0(4, a1);
}

}
