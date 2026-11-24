// bin: proto
// va: 0x002F2050
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2050 (Proto 0x002F2050, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403FD8;
extern "C" int DAT_00403FDC;
extern "C" unsigned short DAT_00403FE4;
extern "C" unsigned short DAT_00403FE6;
extern "C" unsigned short DAT_00403FEA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2050(void)
{
    DAT_00403FD8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403FDC);
    DAT_00403FDC = 0;
    DAT_00403FE4 = 0;
    DAT_00403FE6 = 0;
    DAT_00403FEA = 0;
    return 0;
}
