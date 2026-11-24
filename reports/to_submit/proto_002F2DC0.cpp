// bin: proto
// va: 0x002F2DC0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2DC0 (Proto 0x002F2DC0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409D50;
extern "C" int DAT_00409D54;
extern "C" unsigned short DAT_00409D5C;
extern "C" unsigned short DAT_00409D5E;
extern "C" unsigned short DAT_00409D62;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2DC0(void)
{
    DAT_00409D50 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409D54);
    DAT_00409D54 = 0;
    DAT_00409D5C = 0;
    DAT_00409D5E = 0;
    DAT_00409D62 = 0;
    return 0;
}
