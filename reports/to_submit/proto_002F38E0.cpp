// bin: proto
// va: 0x002F38E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F38E0 (Proto 0x002F38E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00410350;
extern "C" int DAT_00410354;
extern "C" unsigned short DAT_0041035C;
extern "C" unsigned short DAT_0041035E;
extern "C" unsigned short DAT_00410362;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F38E0(void)
{
    DAT_00410350 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410354);
    DAT_00410354 = 0;
    DAT_0041035C = 0;
    DAT_0041035E = 0;
    DAT_00410362 = 0;
    return 0;
}
