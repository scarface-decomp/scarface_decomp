// bin: pc
// va: 0x006F4E60
// tool: the portal's starter code (no AI)
// audio::OggVorbisStream::vfunc_08 (0x006F4E60, 27 bytes)
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
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual bool vfunc_08(int a1);
    char m_pad04[0x2E4];
    int m_Field2E8; // +0x2E8
};

bool OggVorbisStream::vfunc_08(int a1)
{
    *(int*)a1 = m_Field2E8;
    m_Field2E8 = 0;
    return true;
}

}
