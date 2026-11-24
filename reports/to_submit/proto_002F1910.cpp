// bin: proto
// va: 0x002F1910
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1910 (Proto 0x002F1910, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403ADC;
extern "C" int DAT_00403AE0;
extern "C" unsigned short DAT_00403AE8;
extern "C" unsigned short DAT_00403AEA;
extern "C" unsigned short DAT_00403AEE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1910(void)
{
    DAT_00403ADC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403AE0);
    DAT_00403AE0 = 0;
    DAT_00403AE8 = 0;
    DAT_00403AEA = 0;
    DAT_00403AEE = 0;
    return 0;
}
