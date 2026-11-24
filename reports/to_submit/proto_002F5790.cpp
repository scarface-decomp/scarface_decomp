// bin: proto
// va: 0x002F5790
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5790 (Proto 0x002F5790, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00418238;
extern "C" int DAT_0041823C;
extern "C" unsigned short DAT_00418244;
extern "C" unsigned short DAT_00418246;
extern "C" unsigned short DAT_0041824A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5790(void)
{
    DAT_00418238 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041823C);
    DAT_0041823C = 0;
    DAT_00418244 = 0;
    DAT_00418246 = 0;
    DAT_0041824A = 0;
    return 0;
}
