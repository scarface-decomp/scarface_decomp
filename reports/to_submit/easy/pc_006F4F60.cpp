// bin: pc
// va: 0x006F4F60
// tool: the portal's starter code (no AI)
// audio::OggVorbisStream::vfunc_17 (0x006F4F60, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
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
    virtual void vfunc_12();
};

extern "C" char DAT_00772B5C[];
extern "C" char DAT_007F6D80[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_006EE890(int, int);
extern "C" void __cdecl sub_00702724(int);

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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual OggVorbisStream* vfunc_17(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x2CC];
    int m_Field2D8; // +0x2D8
    char m_pad2DC[0x14];
    int m_Field2F0; // +0x2F0
};

OggVorbisStream* OggVorbisStream::vfunc_17(int a1)
{
    int t1;

    t1 = m_Field04;
    *(int*)this = (int)DAT_00772B5C;
    ((Object*)t1)->vfunc_12();
    sub_0043CE70(m_Field2F0);
    if (m_Field2D8) {
        sub_00702724((int)(&m_Field08));
    }
    sub_0043CE70(m_Field2D8);
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F6D80, (int)this);
    }
    return this;
}

}
