// bin: proto
// va: 0x002F2D40
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2D40 (Proto 0x002F2D40, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409B78;
extern "C" int DAT_00409B7C;
extern "C" unsigned short DAT_00409B84;
extern "C" unsigned short DAT_00409B86;
extern "C" unsigned short DAT_00409B8A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2D40(void)
{
    DAT_00409B78 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409B7C);
    DAT_00409B7C = 0;
    DAT_00409B84 = 0;
    DAT_00409B86 = 0;
    DAT_00409B8A = 0;
    return 0;
}
