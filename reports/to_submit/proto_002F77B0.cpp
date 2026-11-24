// bin: proto
// va: 0x002F77B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F77B0 (Proto 0x002F77B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004276B8;
extern "C" int DAT_004276BC;
extern "C" unsigned short DAT_004276C4;
extern "C" unsigned short DAT_004276C6;
extern "C" unsigned short DAT_004276CA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F77B0(void)
{
    DAT_004276B8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004276BC);
    DAT_004276BC = 0;
    DAT_004276C4 = 0;
    DAT_004276C6 = 0;
    DAT_004276CA = 0;
    return 0;
}
