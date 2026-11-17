// bin: pc
// va: 0x006F7920
// tool: the portal's starter code (no AI)
// audio::SeqActionWait::vfunc_04 (0x006F7920, 15 bytes)
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
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
};

void SeqActionWait::vfunc_04(int a1)
{
    sub_006F57A0(5, a1);
}

}
