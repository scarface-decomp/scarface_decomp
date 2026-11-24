// bin: proto
// va: 0x002F43E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F43E0 (Proto 0x002F43E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041233C;
extern "C" int DAT_00412340;
extern "C" unsigned short DAT_00412348;
extern "C" unsigned short DAT_0041234A;
extern "C" unsigned short DAT_0041234E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F43E0(void)
{
    DAT_0041233C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00412340);
    DAT_00412340 = 0;
    DAT_00412348 = 0;
    DAT_0041234A = 0;
    DAT_0041234E = 0;
    return 0;
}
