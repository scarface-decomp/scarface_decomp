// bin: pc
// va: 0x006F78E0
// tool: the portal's starter code (no AI)
// audio::SeqActionWait::vfunc_02 (0x006F78E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006F57A0(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2);
};

void SeqActionWait::vfunc_02(int a1, int a2)
{
    a2 = a1;
    a1 = 1;
    sub_006F57A0(a1, a2);
}

}
