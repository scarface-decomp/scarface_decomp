// bin: pc
// va: 0x006F4D00
// tool: the portal's starter code (no AI)
// audio::OggVorbisStream::vfunc_00 (0x006F4D00, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    virtual void vfunc_00();
    virtual int vfunc_01();
};

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
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    Field04* m_Field04; // +0x04
    char m_pad08[0x2E4];
    int m_Field2EC; // +0x2EC
};

void OggVorbisStream::vfunc_00()
{
    if (!m_Field04->vfunc_01()) {
        m_Field04->vfunc_00();
    }
    m_Field2EC = 1;
    vfunc_11();
}

}
