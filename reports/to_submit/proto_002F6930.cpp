// bin: proto
// va: 0x002F6930
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6930 (Proto 0x002F6930, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004211EC;
extern "C" int DAT_004211F0;
extern "C" unsigned short DAT_004211F8;
extern "C" unsigned short DAT_004211FA;
extern "C" unsigned short DAT_004211FE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6930(void)
{
    DAT_004211EC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004211F0);
    DAT_004211F0 = 0;
    DAT_004211F8 = 0;
    DAT_004211FA = 0;
    DAT_004211FE = 0;
    return 0;
}
