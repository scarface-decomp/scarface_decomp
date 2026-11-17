// bin: pc
// va: 0x006F54C0
// tool: the portal's starter code (no AI)
// audio::HalRadicalAdpcmDecodeStream::vfunc_00 (0x006F54C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    virtual void vfunc_00();
};

struct Object
{
    virtual void vfunc_00();
    virtual int vfunc_01();
};

namespace audio {

class HalRadicalAdpcmDecodeStream
{
public:
    virtual void vfunc_00();
    Field04* m_Field04; // +0x04
    char m_pad08[0x14];
    int m_Field1C; // +0x1C
};

void HalRadicalAdpcmDecodeStream::vfunc_00()
{
    Field04* t1;

    t1 = m_Field04;
    m_Field1C = 1;
    if (!((Object*)(int)t1)->vfunc_01()) {
        m_Field04->vfunc_00();
        return;
    }
}

}
