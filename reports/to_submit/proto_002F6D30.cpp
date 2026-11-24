// bin: proto
// va: 0x002F6D30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6D30 (Proto 0x002F6D30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0042150C;
extern "C" int DAT_00421510;
extern "C" unsigned short DAT_00421518;
extern "C" unsigned short DAT_0042151A;
extern "C" unsigned short DAT_0042151E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6D30(void)
{
    DAT_0042150C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421510);
    DAT_00421510 = 0;
    DAT_00421518 = 0;
    DAT_0042151A = 0;
    DAT_0042151E = 0;
    return 0;
}
