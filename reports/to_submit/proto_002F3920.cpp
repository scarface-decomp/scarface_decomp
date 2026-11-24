// bin: proto
// va: 0x002F3920
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3920 (Proto 0x002F3920, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00410410;
extern "C" int DAT_00410414;
extern "C" unsigned short DAT_0041041C;
extern "C" unsigned short DAT_0041041E;
extern "C" unsigned short DAT_00410422;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3920(void)
{
    DAT_00410410 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410414);
    DAT_00410414 = 0;
    DAT_0041041C = 0;
    DAT_0041041E = 0;
    DAT_00410422 = 0;
    return 0;
}
