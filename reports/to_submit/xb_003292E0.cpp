// bin: xb
// va: 0x003292E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003292E0 (0x003292E0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" int DAT_00492ED4;

void __cdecl sub_003292E0(void)
{
    int t1;

    t1 = DAT_00492ED4;
    if (DAT_00492ED4) {
        DAT_00492ED4 = 0;
        ((Object*)t1)->vfunc_01();
        return;
    }
}
