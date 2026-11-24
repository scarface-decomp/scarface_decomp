// bin: proto
// va: 0x002F5E50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5E50 (Proto 0x002F5E50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041A9D4;
extern "C" int DAT_0041A9D8;
extern "C" unsigned short DAT_0041A9E0;
extern "C" unsigned short DAT_0041A9E2;
extern "C" unsigned short DAT_0041A9E6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5E50(void)
{
    DAT_0041A9D4 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041A9D8);
    DAT_0041A9D8 = 0;
    DAT_0041A9E0 = 0;
    DAT_0041A9E2 = 0;
    DAT_0041A9E6 = 0;
    return 0;
}
