// bin: proto
// va: 0x002F2A30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2A30 (Proto 0x002F2A30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409364;
extern "C" int DAT_00409368;
extern "C" unsigned short DAT_00409370;
extern "C" unsigned short DAT_00409372;
extern "C" unsigned short DAT_00409376;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2A30(void)
{
    DAT_00409364 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409368);
    DAT_00409368 = 0;
    DAT_00409370 = 0;
    DAT_00409372 = 0;
    DAT_00409376 = 0;
    return 0;
}
