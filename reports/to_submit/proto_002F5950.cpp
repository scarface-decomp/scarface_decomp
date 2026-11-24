// bin: proto
// va: 0x002F5950
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5950 (Proto 0x002F5950, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00419250;
extern "C" int DAT_00419254;
extern "C" unsigned short DAT_0041925C;
extern "C" unsigned short DAT_0041925E;
extern "C" unsigned short DAT_00419262;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5950(void)
{
    DAT_00419250 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00419254);
    DAT_00419254 = 0;
    DAT_0041925C = 0;
    DAT_0041925E = 0;
    DAT_00419262 = 0;
    return 0;
}
