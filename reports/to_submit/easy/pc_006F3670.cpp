// bin: pc
// va: 0x006F3670
// tool: the portal's starter code (no AI)
// audio::HalRsdFileStream::vfunc_08 (0x006F3670, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class HalRsdFileStream
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
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
    char m_pad40[0x4];
    unsigned short m_Field44; // +0x44
};

bool HalRsdFileStream::vfunc_08(int a1)
{
    if (m_Field44 == 5) {
        return false;
    }
    *(int*)a1 = m_Field3C;
    m_Field44 = 4;
    return true;
}

}
