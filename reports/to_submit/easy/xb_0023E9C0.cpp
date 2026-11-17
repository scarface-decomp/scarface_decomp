// bin: xb
// va: 0x0023E9C0
// tool: the portal's starter code (no AI)
// FightTree::FightActionController<fight::SequenceTrack>::vfunc_20 (0x0023E9C0, 96 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_00239CC0();
};

extern "C" char DAT_003D48A0[];
extern "C" int __cdecl sub_00027590(int);

namespace fight { class SequenceTrack; }

namespace FightTree { 
template <class T0> class FightActionController
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
    virtual int vfunc_20(int a1);
};
}

template <> int FightTree::FightActionController<fight::SequenceTrack>::vfunc_20(int a1)
{
    int r_edi, r_esi, t5;

    r_edi = (int)this;
    r_esi = sub_00027590(16);
    if (r_esi) {
        ((Object*)r_esi)->sub_00239CC0();
        *(int*)r_esi = (int)DAT_003D48A0;
        *(int*)(r_esi + 12) = 0;
        *(int*)(r_esi + 8) = (int)this;
        ((Object*)r_edi)->vfunc_00();
        r_edi = a1;
        if (a1) {
            ((Object*)r_edi)->vfunc_00();
        }
        t5 = *(int*)(r_esi + 12);
        if (*(int*)(r_esi + 12)) {
            ((Object*)t5)->vfunc_01();
        }
        *(int*)(r_esi + 12) = r_edi;
        return r_esi;
    }
    return 0;
}
