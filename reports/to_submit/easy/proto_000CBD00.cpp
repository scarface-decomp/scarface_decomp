// bin: proto
// va: 0x000CBD00
// tool: the portal's starter code (no AI)
// WeaponGroupCondition::vfunc_15 (0x000CBD00, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00148290();
};

extern "C" int DAT_003FF730[];
extern "C" int __cdecl sub_00028120(int);

class WeaponGroupCondition
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
    virtual bool vfunc_15(int a1, int a2);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

bool WeaponGroupCondition::vfunc_15(int a1, int a2)
{
    int t2;

    if (a1) {
        t2 = sub_00028120(*(int*)(a1 + 28));
        if (!t2) goto L_37;
        return m_Field10 == DAT_003FF730[((Object*)t2)->sub_00148290()];
    }
L_37:
    return false;
}
