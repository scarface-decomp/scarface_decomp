// bin: proto
// va: 0x002F1810
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1810 (Proto 0x002F1810, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004032D0;
extern "C" int DAT_004032D4;
extern "C" unsigned short DAT_004032DC;
extern "C" unsigned short DAT_004032DE;
extern "C" unsigned short DAT_004032E2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1810(void)
{
    DAT_004032D0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004032D4);
    DAT_004032D4 = 0;
    DAT_004032DC = 0;
    DAT_004032DE = 0;
    DAT_004032E2 = 0;
    return 0;
}
