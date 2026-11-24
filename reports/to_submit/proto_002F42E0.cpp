// bin: proto
// va: 0x002F42E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F42E0 (Proto 0x002F42E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00411D80;
extern "C" int DAT_00411D84;
extern "C" unsigned short DAT_00411D8C;
extern "C" unsigned short DAT_00411D8E;
extern "C" unsigned short DAT_00411D92;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F42E0(void)
{
    DAT_00411D80 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00411D84);
    DAT_00411D84 = 0;
    DAT_00411D8C = 0;
    DAT_00411D8E = 0;
    DAT_00411D92 = 0;
    return 0;
}
