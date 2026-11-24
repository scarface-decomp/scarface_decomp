// bin: proto
// va: 0x002F7330
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7330 (Proto 0x002F7330, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00425838;
extern "C" int DAT_0042583C;
extern "C" unsigned short DAT_00425844;
extern "C" unsigned short DAT_00425846;
extern "C" unsigned short DAT_0042584A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F7330(void)
{
    DAT_00425838 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0042583C);
    DAT_0042583C = 0;
    DAT_00425844 = 0;
    DAT_00425846 = 0;
    DAT_0042584A = 0;
    return 0;
}
