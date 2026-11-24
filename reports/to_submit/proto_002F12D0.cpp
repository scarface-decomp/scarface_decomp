// bin: proto
// va: 0x002F12D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F12D0 (Proto 0x002F12D0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00291040();
};

extern "C" char DAT_004538D8[];

void __cdecl sub_002F12D0(void)
{
    int r_edi, r_esi;

    r_esi = (int)DAT_004538D8;
    r_edi = 2;
    do {
        r_esi -= 72;
        ((Object*)r_esi + 16)->sub_00291040();
        ((Object*)r_esi)->sub_00291040();
        r_edi -= 1;
    } while (r_edi);
}
