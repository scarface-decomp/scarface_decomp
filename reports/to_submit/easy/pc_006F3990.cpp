// bin: pc
// va: 0x006F3990
// tool: the portal's starter code (no AI)
// audio::HalRsdFileStream::vfunc_12 (0x006F3990, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_006EBBD0();
};

struct Field20
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_007F6D44[];
extern "C" char DAT_007F6D4C[];
extern "C" void __cdecl sub_006EE890(int, int);

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
    virtual void vfunc_15(int);
    Field10 m_Field04; // +0x04
    char m_pad05[0xB];
    Field10 m_Field10; // +0x10
    char m_pad11[0xF];
    Field20* m_Field20; // +0x20
    int m_Field24; // +0x24
};

void HalRsdFileStream::vfunc_12()
{
    int t3;

    if (m_Field20) {
        vfunc_15(4);
        m_Field20->vfunc_01();
    }
    t3 = m_Field24;
    if (m_Field24) {
        sub_006EE890((int)DAT_007F6D44, t3);
    }
    m_Field10.sub_006EBBD0();
    m_Field04.sub_006EBBD0();
    sub_006EE890((int)DAT_007F6D4C, (int)this);
}

}
