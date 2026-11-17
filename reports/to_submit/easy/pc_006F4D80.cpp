// bin: pc
// va: 0x006F4D80
// tool: the portal's starter code (no AI)
// audio::OggVorbisStream::vfunc_01 (0x006F4D80, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x2E8];
    int m_Field2EC; // +0x2EC
};

int OggVorbisStream::vfunc_01()
{
    return m_Field2EC;
}

}
