// bin: proto
// va: 0x002F57D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F57D0 (Proto 0x002F57D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00418728;
extern "C" int DAT_0041872C;
extern "C" unsigned short DAT_00418734;
extern "C" unsigned short DAT_00418736;
extern "C" unsigned short DAT_0041873A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F57D0(void)
{
    DAT_00418728 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041872C);
    DAT_0041872C = 0;
    DAT_00418734 = 0;
    DAT_00418736 = 0;
    DAT_0041873A = 0;
    return 0;
}
