// bin: proto
// va: 0x002F2410
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2410 (Proto 0x002F2410, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040426C;
extern "C" int DAT_00404270;
extern "C" unsigned short DAT_00404278;
extern "C" unsigned short DAT_0040427A;
extern "C" unsigned short DAT_0040427E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2410(void)
{
    DAT_0040426C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404270);
    DAT_00404270 = 0;
    DAT_00404278 = 0;
    DAT_0040427A = 0;
    DAT_0040427E = 0;
    return 0;
}
