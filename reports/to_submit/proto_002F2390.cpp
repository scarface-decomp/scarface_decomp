// bin: proto
// va: 0x002F2390
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2390 (Proto 0x002F2390, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404214;
extern "C" int DAT_00404218;
extern "C" unsigned short DAT_00404220;
extern "C" unsigned short DAT_00404222;
extern "C" unsigned short DAT_00404226;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2390(void)
{
    DAT_00404214 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404218);
    DAT_00404218 = 0;
    DAT_00404220 = 0;
    DAT_00404222 = 0;
    DAT_00404226 = 0;
    return 0;
}
