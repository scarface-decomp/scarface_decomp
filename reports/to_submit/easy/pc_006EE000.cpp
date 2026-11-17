// bin: pc
// va: 0x006EE000
// tool: the portal's starter code (no AI)
// audio::MixerMix::vfunc_01 (0x006EE000, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class MixerMix
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void MixerMix::vfunc_01()
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = *(int*)(r_ecx + 72);
    if (r_eax == 1) {
        r_eax = *(int*)r_ecx;
        ((void (__stdcall*)(int))*(int*)(r_eax + 12))(1);
        return;
    }
    r_eax += -1;
    *(int*)(r_ecx + 72) = r_eax;
}

}
