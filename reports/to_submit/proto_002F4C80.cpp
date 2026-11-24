// bin: proto
// va: 0x002F4C80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4C80 (Proto 0x002F4C80, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00415040;
extern "C" int DAT_00415044;
extern "C" unsigned short DAT_0041504C;
extern "C" unsigned short DAT_0041504E;
extern "C" unsigned short DAT_00415052;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4C80(void)
{
    DAT_00415040 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00415044);
    DAT_00415044 = 0;
    DAT_0041504C = 0;
    DAT_0041504E = 0;
    DAT_00415052 = 0;
    return 0;
}
