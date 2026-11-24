// bin: proto
// va: 0x002F5D10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5D10 (Proto 0x002F5D10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041A330;
extern "C" int DAT_0041A334;
extern "C" unsigned short DAT_0041A33C;
extern "C" unsigned short DAT_0041A33E;
extern "C" unsigned short DAT_0041A342;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5D10(void)
{
    DAT_0041A330 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041A334);
    DAT_0041A334 = 0;
    DAT_0041A33C = 0;
    DAT_0041A33E = 0;
    DAT_0041A342 = 0;
    return 0;
}
