// bin: proto
// va: 0x002F4560
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4560 (Proto 0x002F4560, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00413408;
extern "C" int DAT_0041340C;
extern "C" unsigned short DAT_00413414;
extern "C" unsigned short DAT_00413416;
extern "C" unsigned short DAT_0041341A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4560(void)
{
    DAT_00413408 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041340C);
    DAT_0041340C = 0;
    DAT_00413414 = 0;
    DAT_00413416 = 0;
    DAT_0041341A = 0;
    return 0;
}
