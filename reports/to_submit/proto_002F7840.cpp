// bin: proto
// va: 0x002F7840
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7840 (Proto 0x002F7840, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" int DAT_00463920;
extern "C" int DAT_00463924[];

void __cdecl sub_002F7840(void)
{
    int r_esi;

    r_esi = DAT_00463920;
    r_esi -= 1;
    if (r_esi >= 0) {
        do {
            ((Object*)DAT_00463924[r_esi])->vfunc_01();
            r_esi -= 1;
        } while (r_esi >= 0);
    }
}
