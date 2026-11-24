// bin: proto
// va: 0x002F1F90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1F90 (Proto 0x002F1F90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403F54;
extern "C" int DAT_00403F58;
extern "C" unsigned short DAT_00403F60;
extern "C" unsigned short DAT_00403F62;
extern "C" unsigned short DAT_00403F66;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1F90(void)
{
    DAT_00403F54 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403F58);
    DAT_00403F58 = 0;
    DAT_00403F60 = 0;
    DAT_00403F62 = 0;
    DAT_00403F66 = 0;
    return 0;
}
