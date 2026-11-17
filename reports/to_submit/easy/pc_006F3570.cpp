// bin: pc
// va: 0x006F3570
// tool: the portal's starter code (no AI)
// audio::HalRsdFileStream::vfunc_09 (0x006F3570, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772AD4[];

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
    virtual void vfunc_08();
    virtual int vfunc_09(int a1);
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

int HalRsdFileStream::vfunc_09(int a1)
{
    int r_eax;

    r_eax = m_Field24;
    if (!r_eax) {
        r_eax = (int)DAT_00772AD4;
        return r_eax;
    }
    r_eax = (a1 << 4) + r_eax + 164;
    return r_eax;
}

}
