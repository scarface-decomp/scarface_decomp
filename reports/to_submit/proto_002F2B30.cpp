// bin: proto
// va: 0x002F2B30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2B30 (Proto 0x002F2B30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409414;
extern "C" int DAT_00409418;
extern "C" unsigned short DAT_00409420;
extern "C" unsigned short DAT_00409422;
extern "C" unsigned short DAT_00409426;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2B30(void)
{
    DAT_00409414 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409418);
    DAT_00409418 = 0;
    DAT_00409420 = 0;
    DAT_00409422 = 0;
    DAT_00409426 = 0;
    return 0;
}
