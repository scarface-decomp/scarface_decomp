// bin: proto
// va: 0x002F4E00
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4E00 (Proto 0x002F4E00, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00415990;
extern "C" int DAT_00415994;
extern "C" unsigned short DAT_0041599C;
extern "C" unsigned short DAT_0041599E;
extern "C" unsigned short DAT_004159A2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4E00(void)
{
    DAT_00415990 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00415994);
    DAT_00415994 = 0;
    DAT_0041599C = 0;
    DAT_0041599E = 0;
    DAT_004159A2 = 0;
    return 0;
}
