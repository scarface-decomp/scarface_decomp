// bin: pc
// va: 0x006F38C0
// what: 
// tool: the portal's starter code (no AI)

// audio::HalRsdFileStream::vfunc_15 (PC 0x006F38C0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D360;

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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual int vfunc_15(int a1);
    char m_pad04[0x3D];
    unsigned char m_Field41; // +0x41
    char m_pad42[0x6];
    int m_Field48; // +0x48
};

int HalRsdFileStream::vfunc_15(int a1)
{
    int r_eax;

    r_eax = DAT_0085D360;
    if (r_eax) {
        if (!m_Field41) goto L_29;
        r_eax = ((int (__cdecl*)(int, int, int, int, int))r_eax)((int)(&m_Field48), a1, 0, 0, 0);
        m_Field41 = (unsigned char)r_eax;
    }
L_29:
    return r_eax;
}

}
