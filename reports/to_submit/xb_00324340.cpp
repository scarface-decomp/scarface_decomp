// bin: xb
// va: 0x00324340
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324340 (0x00324340, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" int DAT_00489D9C;
extern "C" int DAT_00489DA0;
extern "C" int DAT_00489DA8;
extern "C" void __cdecl sub_00125070(int, int);

void __cdecl sub_00324340(void)
{
    int t2;

    sub_00125070(DAT_00489D9C, DAT_00489DA0);
    t2 = DAT_00489D9C;
    DAT_00489DA0 = DAT_00489D9C;
    if (DAT_00489D9C) {
        ((Object*)DAT_00489DA8)->vfunc_05(t2);
    }
    ((Object*)DAT_00489DA8)->vfunc_01();
}
