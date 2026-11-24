// bin: proto
// va: 0x002F2690
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2690 (Proto 0x002F2690, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404424;
extern "C" int DAT_00404428;
extern "C" unsigned short DAT_00404430;
extern "C" unsigned short DAT_00404432;
extern "C" unsigned short DAT_00404436;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2690(void)
{
    DAT_00404424 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404428);
    DAT_00404428 = 0;
    DAT_00404430 = 0;
    DAT_00404432 = 0;
    DAT_00404436 = 0;
    return 0;
}
