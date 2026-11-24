// bin: proto
// va: 0x002F2710
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2710 (Proto 0x002F2710, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040447C;
extern "C" int DAT_00404480;
extern "C" unsigned short DAT_00404488;
extern "C" unsigned short DAT_0040448A;
extern "C" unsigned short DAT_0040448E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2710(void)
{
    DAT_0040447C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404480);
    DAT_00404480 = 0;
    DAT_00404488 = 0;
    DAT_0040448A = 0;
    DAT_0040448E = 0;
    return 0;
}
