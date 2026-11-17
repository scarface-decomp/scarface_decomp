// bin: pc
// va: 0x006FD9F0
// tool: the portal's starter code (no AI)
// SoundLoadSequence::vfunc_00 (0x006FD9F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class SoundLoadSequence
{
public:
    virtual void vfunc_00();
    char m_pad04[0x30];
    unsigned short m_Field34; // +0x34
};

void SoundLoadSequence::vfunc_00()
{
    m_Field34 += 1;
}
