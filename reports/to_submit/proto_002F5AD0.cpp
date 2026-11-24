// bin: proto
// va: 0x002F5AD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5AD0 (Proto 0x002F5AD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00419910;
extern "C" int DAT_00419914;
extern "C" unsigned short DAT_0041991C;
extern "C" unsigned short DAT_0041991E;
extern "C" unsigned short DAT_00419922;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5AD0(void)
{
    DAT_00419910 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00419914);
    DAT_00419914 = 0;
    DAT_0041991C = 0;
    DAT_0041991E = 0;
    DAT_00419922 = 0;
    return 0;
}
