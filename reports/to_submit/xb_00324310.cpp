// bin: xb
// va: 0x00324310
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324310 (0x00324310, 37 bytes)
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

extern "C" int DAT_00489D04;
extern "C" int DAT_00489D08;
extern "C" int DAT_00489D10;

void __cdecl sub_00324310(void)
{
    int t1;

    t1 = DAT_00489D04;
    DAT_00489D08 = DAT_00489D04;
    if (DAT_00489D04) {
        ((Object*)DAT_00489D10)->vfunc_05(t1);
    }
    ((Object*)DAT_00489D10)->vfunc_01();
}
