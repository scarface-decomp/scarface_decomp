// bin: proto
// va: 0x002F2550
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2550 (Proto 0x002F2550, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404348;
extern "C" int DAT_0040434C;
extern "C" unsigned short DAT_00404354;
extern "C" unsigned short DAT_00404356;
extern "C" unsigned short DAT_0040435A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2550(void)
{
    DAT_00404348 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040434C);
    DAT_0040434C = 0;
    DAT_00404354 = 0;
    DAT_00404356 = 0;
    DAT_0040435A = 0;
    return 0;
}
