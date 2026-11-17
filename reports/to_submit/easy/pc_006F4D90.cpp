// bin: pc
// va: 0x006F4D90
// tool: the portal's starter code (no AI)
// audio::OggVorbisStream::vfunc_02 (0x006F4D90, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void* vfunc_02();
    char m_pad04[0x2D8];
    int m_Field2DC; // +0x2DC
};

void* OggVorbisStream::vfunc_02()
{
    return &m_Field2DC;
}

}
