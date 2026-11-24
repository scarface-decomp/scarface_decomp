// bin: proto
// va: 0x002F6070
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6070 (Proto 0x002F6070, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041BBB0;
extern "C" int DAT_0041BBB4;
extern "C" unsigned short DAT_0041BBBC;
extern "C" unsigned short DAT_0041BBBE;
extern "C" unsigned short DAT_0041BBC2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6070(void)
{
    DAT_0041BBB0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041BBB4);
    DAT_0041BBB4 = 0;
    DAT_0041BBBC = 0;
    DAT_0041BBBE = 0;
    DAT_0041BBC2 = 0;
    return 0;
}
