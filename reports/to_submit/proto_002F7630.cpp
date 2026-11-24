// bin: proto
// va: 0x002F7630
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7630 (Proto 0x002F7630, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00426E64;
extern "C" int DAT_00426E68;
extern "C" unsigned short DAT_00426E70;
extern "C" unsigned short DAT_00426E72;
extern "C" unsigned short DAT_00426E76;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F7630(void)
{
    DAT_00426E64 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00426E68);
    DAT_00426E68 = 0;
    DAT_00426E70 = 0;
    DAT_00426E72 = 0;
    DAT_00426E76 = 0;
    return 0;
}
