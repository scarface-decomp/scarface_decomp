// bin: proto
// va: 0x002F1D90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1D90 (Proto 0x002F1D90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403DF4;
extern "C" int DAT_00403DF8;
extern "C" unsigned short DAT_00403E00;
extern "C" unsigned short DAT_00403E02;
extern "C" unsigned short DAT_00403E06;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1D90(void)
{
    DAT_00403DF4 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403DF8);
    DAT_00403DF8 = 0;
    DAT_00403E00 = 0;
    DAT_00403E02 = 0;
    DAT_00403E06 = 0;
    return 0;
}
