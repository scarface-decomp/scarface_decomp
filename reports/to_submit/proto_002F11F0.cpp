// bin: proto
// va: 0x002F11F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F11F0 (Proto 0x002F11F0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" int DAT_0044AE78;

void __cdecl sub_002F11F0(void)
{
    int t1;

    t1 = DAT_0044AE78;
    if (DAT_0044AE78) {
        DAT_0044AE78 = 0;
        ((Object*)t1)->vfunc_01();
        return;
    }
}
