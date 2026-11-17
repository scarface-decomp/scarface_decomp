// bin: pc
// va: 0x006EDFF0
// tool: the portal's starter code (no AI)
// audio::MixerMix::vfunc_00 (0x006EDFF0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class MixerMix
{
public:
    virtual void vfunc_00();
    char m_pad04[0x44];
    int m_Field48; // +0x48
};

void MixerMix::vfunc_00()
{
    m_Field48 += 1;
}

}
