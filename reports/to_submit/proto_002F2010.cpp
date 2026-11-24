// bin: proto
// va: 0x002F2010
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2010 (Proto 0x002F2010, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403FAC;
extern "C" int DAT_00403FB0;
extern "C" unsigned short DAT_00403FB8;
extern "C" unsigned short DAT_00403FBA;
extern "C" unsigned short DAT_00403FBE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2010(void)
{
    DAT_00403FAC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403FB0);
    DAT_00403FB0 = 0;
    DAT_00403FB8 = 0;
    DAT_00403FBA = 0;
    DAT_00403FBE = 0;
    return 0;
}
