// bin: proto
// va: 0x002F3410
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3410 (Proto 0x002F3410, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040C818;
extern "C" int DAT_0040C81C;
extern "C" unsigned short DAT_0040C824;
extern "C" unsigned short DAT_0040C826;
extern "C" unsigned short DAT_0040C82A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3410(void)
{
    DAT_0040C818 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040C81C);
    DAT_0040C81C = 0;
    DAT_0040C824 = 0;
    DAT_0040C826 = 0;
    DAT_0040C82A = 0;
    return 0;
}
