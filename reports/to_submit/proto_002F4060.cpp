// bin: proto
// va: 0x002F4060
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4060 (Proto 0x002F4060, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00411848;
extern "C" int DAT_0041184C;
extern "C" unsigned short DAT_00411854;
extern "C" unsigned short DAT_00411856;
extern "C" unsigned short DAT_0041185A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4060(void)
{
    DAT_00411848 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041184C);
    DAT_0041184C = 0;
    DAT_00411854 = 0;
    DAT_00411856 = 0;
    DAT_0041185A = 0;
    return 0;
}
