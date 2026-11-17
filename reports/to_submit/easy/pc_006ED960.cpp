// bin: pc
// va: 0x006ED960
// tool: the portal's starter code (no AI)
// audio::Sequence::vfunc_07 (0x006ED960, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);

namespace audio {

class Sequence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07(int a1);
    bool sub_006ED5C0(int);
    bool sub_006ED820(int);
};

int Sequence::vfunc_07(int a1)
{
    if (sub_006F33F0(a1, 1)) {
        if (!sub_006ED820(a1)) goto L_39;
        if (!sub_006ED5C0(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}
