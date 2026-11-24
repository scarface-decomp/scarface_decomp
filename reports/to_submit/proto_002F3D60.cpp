// bin: proto
// va: 0x002F3D60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3D60 (Proto 0x002F3D60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00410DE4;
extern "C" int DAT_00410DE8;
extern "C" unsigned short DAT_00410DF0;
extern "C" unsigned short DAT_00410DF2;
extern "C" unsigned short DAT_00410DF6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3D60(void)
{
    DAT_00410DE4 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410DE8);
    DAT_00410DE8 = 0;
    DAT_00410DF0 = 0;
    DAT_00410DF2 = 0;
    DAT_00410DF6 = 0;
    return 0;
}
