// bin: proto
// va: 0x000D6FE0
// tool: the portal's starter code (no AI)
// AnimationTrack::vfunc_22 (0x000D6FE0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000C94A0(int, int);
    bool sub_00147B40();
};

extern "C" int __cdecl sub_00028120(int);

class AnimationTrack
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
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual bool vfunc_22(int a1);
};

bool AnimationTrack::vfunc_22(int a1)
{
    int t1;

    if (a1) {
        t1 = *(int*)(a1 + 16);
        if (!*(int*)(a1 + 16)) goto L_3C;
        if (((Object*)sub_00028120(*(int*)(a1 + 28)))->sub_00147B40()) goto L_3C;
        return ((Object*)t1)->sub_000C94A0((int)this + 28, 0);
    }
L_3C:
    return true;
}
