// bin: proto
// va: 0x002F3DE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3DE0 (Proto 0x002F3DE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00410E84;
extern "C" int DAT_00410E88;
extern "C" unsigned short DAT_00410E90;
extern "C" unsigned short DAT_00410E92;
extern "C" unsigned short DAT_00410E96;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3DE0(void)
{
    DAT_00410E84 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410E88);
    DAT_00410E88 = 0;
    DAT_00410E90 = 0;
    DAT_00410E92 = 0;
    DAT_00410E96 = 0;
    return 0;
}
