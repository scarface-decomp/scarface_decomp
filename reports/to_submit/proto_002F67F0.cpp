// bin: proto
// va: 0x002F67F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F67F0 (Proto 0x002F67F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421110;
extern "C" int DAT_00421114;
extern "C" unsigned short DAT_0042111C;
extern "C" unsigned short DAT_0042111E;
extern "C" unsigned short DAT_00421122;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F67F0(void)
{
    DAT_00421110 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421114);
    DAT_00421114 = 0;
    DAT_0042111C = 0;
    DAT_0042111E = 0;
    DAT_00421122 = 0;
    return 0;
}
