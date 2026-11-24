// bin: proto
// va: 0x002F36E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F36E0 (Proto 0x002F36E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040FEEC;
extern "C" int DAT_0040FEF0;
extern "C" unsigned short DAT_0040FEF8;
extern "C" unsigned short DAT_0040FEFA;
extern "C" unsigned short DAT_0040FEFE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F36E0(void)
{
    DAT_0040FEEC = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040FEF0);
    DAT_0040FEF0 = 0;
    DAT_0040FEF8 = 0;
    DAT_0040FEFA = 0;
    DAT_0040FEFE = 0;
    return 0;
}
