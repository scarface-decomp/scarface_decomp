// bin: proto
// va: 0x002F3E60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3E60 (Proto 0x002F3E60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00410EDC;
extern "C" int DAT_00410EE0;
extern "C" unsigned short DAT_00410EE8;
extern "C" unsigned short DAT_00410EEA;
extern "C" unsigned short DAT_00410EEE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3E60(void)
{
    DAT_00410EDC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410EE0);
    DAT_00410EE0 = 0;
    DAT_00410EE8 = 0;
    DAT_00410EEA = 0;
    DAT_00410EEE = 0;
    return 0;
}
