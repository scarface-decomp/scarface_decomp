// bin: proto
// va: 0x002F1C10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1C10 (Proto 0x002F1C10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403CEC;
extern "C" int DAT_00403CF0;
extern "C" unsigned short DAT_00403CF8;
extern "C" unsigned short DAT_00403CFA;
extern "C" unsigned short DAT_00403CFE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1C10(void)
{
    DAT_00403CEC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403CF0);
    DAT_00403CF0 = 0;
    DAT_00403CF8 = 0;
    DAT_00403CFA = 0;
    DAT_00403CFE = 0;
    return 0;
}
