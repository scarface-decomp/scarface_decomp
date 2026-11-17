// bin: proto
// va: 0x001BD870
// tool: the portal's starter code (no AI)
// sub_001BD870 (0x001BD870, 41 bytes)
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual bool vfunc_23(int);
    int sub_0008D4E0(int);
};

extern "C" Object DAT_004615C4;
extern "C" int DAT_004615C8;

bool __cdecl sub_001BD870(int a1)
{
    if (a1) {
        return ((Object*)a1)->vfunc_23(DAT_004615C4.sub_0008D4E0(DAT_004615C8));
    }
    return false;
}
