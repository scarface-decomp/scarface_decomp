// bin: pc
// va: 0x006FA6A0
// tool: the portal's starter code (no AI)
// audio::SeqActionWaitBeat::vfunc_03 (0x006FA6A0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
};

void SeqActionWaitBeat::vfunc_03(int a1)
{
    sub_006F57A0(2, a1);
}

}
