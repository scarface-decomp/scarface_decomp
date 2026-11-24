// bin: proto
// va: 0x002F4020
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4020 (Proto 0x002F4020, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004117A8;
extern "C" int DAT_004117AC;
extern "C" unsigned short DAT_004117B4;
extern "C" unsigned short DAT_004117B6;
extern "C" unsigned short DAT_004117BA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4020(void)
{
    DAT_004117A8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004117AC);
    DAT_004117AC = 0;
    DAT_004117B4 = 0;
    DAT_004117B6 = 0;
    DAT_004117BA = 0;
    return 0;
}
