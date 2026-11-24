// bin: proto
// va: 0x002F5200
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5200 (Proto 0x002F5200, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417340;
extern "C" int DAT_00417344;
extern "C" unsigned short DAT_0041734C;
extern "C" unsigned short DAT_0041734E;
extern "C" unsigned short DAT_00417352;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5200(void)
{
    DAT_00417340 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417344);
    DAT_00417344 = 0;
    DAT_0041734C = 0;
    DAT_0041734E = 0;
    DAT_00417352 = 0;
    return 0;
}
