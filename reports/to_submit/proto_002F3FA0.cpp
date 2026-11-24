// bin: proto
// va: 0x002F3FA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3FA0 (Proto 0x002F3FA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004116D8;
extern "C" int DAT_004116DC;
extern "C" unsigned short DAT_004116E4;
extern "C" unsigned short DAT_004116E6;
extern "C" unsigned short DAT_004116EA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3FA0(void)
{
    DAT_004116D8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004116DC);
    DAT_004116DC = 0;
    DAT_004116E4 = 0;
    DAT_004116E6 = 0;
    DAT_004116EA = 0;
    return 0;
}
