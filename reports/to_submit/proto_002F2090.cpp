// bin: proto
// va: 0x002F2090
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2090 (Proto 0x002F2090, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404004;
extern "C" int DAT_00404008;
extern "C" unsigned short DAT_00404010;
extern "C" unsigned short DAT_00404012;
extern "C" unsigned short DAT_00404016;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2090(void)
{
    DAT_00404004 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404008);
    DAT_00404008 = 0;
    DAT_00404010 = 0;
    DAT_00404012 = 0;
    DAT_00404016 = 0;
    return 0;
}
