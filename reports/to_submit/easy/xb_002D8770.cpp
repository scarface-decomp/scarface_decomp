// bin: xb
// va: 0x002D8770
// tool: the portal's starter code (no AI)
// audio::WmaDecoderStream::vfunc_11 (0x002D8770, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field5C
{
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
};

namespace audio {

class WmaDecoderStream
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
    void sub_002D84E0();
    char m_pad04[0x34];
    int m_Field38; // +0x38
    char m_pad3C[0x20];
    Field5C* m_Field5C; // +0x5C
    char m_pad60[0xAC];
    int m_Field10C; // +0x10C
};

void WmaDecoderStream::vfunc_11()
{
    int r_edi, t4;

    m_Field10C += 1;
    m_Field5C->vfunc_11();
    r_edi = 8;
    if (m_Field38 == 3) goto L_34;
L_20:
    if (r_edi) {
        sub_002D84E0();
        t4 = m_Field38;
        r_edi -= 1;
        if (t4 != 3) goto L_20;
    }
L_34:
    ;
}

}
