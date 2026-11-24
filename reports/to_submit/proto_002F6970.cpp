// bin: proto
// va: 0x002F6970
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6970 (Proto 0x002F6970, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421218;
extern "C" int DAT_0042121C;
extern "C" unsigned short DAT_00421224;
extern "C" unsigned short DAT_00421226;
extern "C" unsigned short DAT_0042122A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6970(void)
{
    DAT_00421218 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0042121C);
    DAT_0042121C = 0;
    DAT_00421224 = 0;
    DAT_00421226 = 0;
    DAT_0042122A = 0;
    return 0;
}
