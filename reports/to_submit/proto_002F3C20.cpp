// bin: proto
// va: 0x002F3C20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3C20 (Proto 0x002F3C20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00410ABC;
extern "C" int DAT_00410AC0;
extern "C" unsigned short DAT_00410AC8;
extern "C" unsigned short DAT_00410ACA;
extern "C" unsigned short DAT_00410ACE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3C20(void)
{
    DAT_00410ABC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410AC0);
    DAT_00410AC0 = 0;
    DAT_00410AC8 = 0;
    DAT_00410ACA = 0;
    DAT_00410ACE = 0;
    return 0;
}
