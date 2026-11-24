// bin: proto
// va: 0x002F4460
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4460 (Proto 0x002F4460, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00412470;
extern "C" int DAT_00412474;
extern "C" unsigned short DAT_0041247C;
extern "C" unsigned short DAT_0041247E;
extern "C" unsigned short DAT_00412482;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4460(void)
{
    DAT_00412470 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00412474);
    DAT_00412474 = 0;
    DAT_0041247C = 0;
    DAT_0041247E = 0;
    DAT_00412482 = 0;
    return 0;
}
