// bin: xb
// va: 0x003292B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003292B0 (0x003292B0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" int DAT_00492C68;
extern "C" int DAT_00492C6C[];

void __cdecl sub_003292B0(void)
{
    int r_esi;

    r_esi = DAT_00492C68;
    r_esi -= 1;
    if (r_esi >= 0) {
        do {
            ((Object*)DAT_00492C6C[r_esi])->vfunc_01();
            r_esi -= 1;
        } while (r_esi >= 0);
    }
}
