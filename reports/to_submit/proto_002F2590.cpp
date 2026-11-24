// bin: proto
// va: 0x002F2590
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2590 (Proto 0x002F2590, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404374;
extern "C" int DAT_00404378;
extern "C" unsigned short DAT_00404380;
extern "C" unsigned short DAT_00404382;
extern "C" unsigned short DAT_00404386;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2590(void)
{
    DAT_00404374 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404378);
    DAT_00404378 = 0;
    DAT_00404380 = 0;
    DAT_00404382 = 0;
    DAT_00404386 = 0;
    return 0;
}
