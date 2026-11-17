// bin: pc
// va: 0x006F5660
// tool: the portal's starter code (no AI)
// audio::HalRadicalAdpcmDecodeStream::vfunc_17 (0x006F5660, 44 bytes)
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

extern "C" char DAT_00772D64[];
extern "C" char DAT_007F6DBC[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class HalRadicalAdpcmDecodeStream
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
    virtual HalRadicalAdpcmDecodeStream* vfunc_17(int a1);
    int m_Field04; // +0x04
};

HalRadicalAdpcmDecodeStream* HalRadicalAdpcmDecodeStream::vfunc_17(int a1)
{
    int t1;

    t1 = m_Field04;
    *(int*)this = (int)DAT_00772D64;
    ((Object*)t1)->vfunc_12();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F6DBC, (int)this);
    }
    return this;
}

}
