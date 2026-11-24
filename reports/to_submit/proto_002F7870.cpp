// bin: proto
// va: 0x002F7870
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7870 (Proto 0x002F7870, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" int DAT_00463B6C;

void __cdecl sub_002F7870(void)
{
    int t1;

    t1 = DAT_00463B6C;
    if (DAT_00463B6C) {
        DAT_00463B6C = 0;
        ((Object*)t1)->vfunc_01();
        return;
    }
}
