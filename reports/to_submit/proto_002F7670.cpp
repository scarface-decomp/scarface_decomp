// bin: proto
// va: 0x002F7670
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7670 (Proto 0x002F7670, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00426E90;
extern "C" int DAT_00426E94;
extern "C" unsigned short DAT_00426E9C;
extern "C" unsigned short DAT_00426E9E;
extern "C" unsigned short DAT_00426EA2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F7670(void)
{
    DAT_00426E90 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00426E94);
    DAT_00426E94 = 0;
    DAT_00426E9C = 0;
    DAT_00426E9E = 0;
    DAT_00426EA2 = 0;
    return 0;
}
