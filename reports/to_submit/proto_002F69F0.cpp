// bin: proto
// va: 0x002F69F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F69F0 (Proto 0x002F69F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421270;
extern "C" int DAT_00421274;
extern "C" unsigned short DAT_0042127C;
extern "C" unsigned short DAT_0042127E;
extern "C" unsigned short DAT_00421282;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F69F0(void)
{
    DAT_00421270 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421274);
    DAT_00421274 = 0;
    DAT_0042127C = 0;
    DAT_0042127E = 0;
    DAT_00421282 = 0;
    return 0;
}
