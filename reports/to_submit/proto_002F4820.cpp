// bin: proto
// va: 0x002F4820
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4820 (Proto 0x002F4820, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00413900;
extern "C" int DAT_00413904;
extern "C" unsigned short DAT_0041390C;
extern "C" unsigned short DAT_0041390E;
extern "C" unsigned short DAT_00413912;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4820(void)
{
    DAT_00413900 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00413904);
    DAT_00413904 = 0;
    DAT_0041390C = 0;
    DAT_0041390E = 0;
    DAT_00413912 = 0;
    return 0;
}
