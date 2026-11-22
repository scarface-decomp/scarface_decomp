// bin: pc
// va: 0x006F4DD0
// what: 
// tool: the portal's starter code (no AI)

// audio::OggVorbisStream::vfunc_04 (PC 0x006F4DD0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x2DC];
    int m_Field2E0; // +0x2E0
    int m_Field2E4; // +0x2E4
};

int OggVorbisStream::vfunc_04()
{
    return m_Field2E0 - m_Field2E4;
}

}
