// bin: proto
// va: 0x002F2110
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2110 (Proto 0x002F2110, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040405C;
extern "C" int DAT_00404060;
extern "C" unsigned short DAT_00404068;
extern "C" unsigned short DAT_0040406A;
extern "C" unsigned short DAT_0040406E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2110(void)
{
    DAT_0040405C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404060);
    DAT_00404060 = 0;
    DAT_00404068 = 0;
    DAT_0040406A = 0;
    DAT_0040406E = 0;
    return 0;
}
