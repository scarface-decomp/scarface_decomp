// bin: proto
// va: 0x002F1D50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1D50 (Proto 0x002F1D50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403DC8;
extern "C" int DAT_00403DCC;
extern "C" unsigned short DAT_00403DD4;
extern "C" unsigned short DAT_00403DD6;
extern "C" unsigned short DAT_00403DDA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1D50(void)
{
    DAT_00403DC8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403DCC);
    DAT_00403DCC = 0;
    DAT_00403DD4 = 0;
    DAT_00403DD6 = 0;
    DAT_00403DDA = 0;
    return 0;
}
