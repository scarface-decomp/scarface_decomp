// bin: proto
// va: 0x002F4D00
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4D00 (Proto 0x002F4D00, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00415098;
extern "C" int DAT_0041509C;
extern "C" unsigned short DAT_004150A4;
extern "C" unsigned short DAT_004150A6;
extern "C" unsigned short DAT_004150AA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4D00(void)
{
    DAT_00415098 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041509C);
    DAT_0041509C = 0;
    DAT_004150A4 = 0;
    DAT_004150A6 = 0;
    DAT_004150AA = 0;
    return 0;
}
