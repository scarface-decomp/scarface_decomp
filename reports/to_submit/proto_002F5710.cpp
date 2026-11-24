// bin: proto
// va: 0x002F5710
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5710 (Proto 0x002F5710, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00418038;
extern "C" int DAT_0041803C;
extern "C" unsigned short DAT_00418044;
extern "C" unsigned short DAT_00418046;
extern "C" unsigned short DAT_0041804A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5710(void)
{
    DAT_00418038 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041803C);
    DAT_0041803C = 0;
    DAT_00418044 = 0;
    DAT_00418046 = 0;
    DAT_0041804A = 0;
    return 0;
}
