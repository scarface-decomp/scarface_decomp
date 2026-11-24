// bin: proto
// va: 0x002F09B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F09B0 (Proto 0x002F09B0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00441434;
extern "C" int DAT_00441438;
extern "C" void __cdecl sub_00025160(int);

void __cdecl sub_002F09B0(void)
{
    int t1;

    t1 = DAT_00441434;
    DAT_00441438 = DAT_00441434;
    if (DAT_00441434) {
        sub_00025160(t1);
    }
}
