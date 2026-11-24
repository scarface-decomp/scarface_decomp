// bin: proto
// va: 0x002F1E50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1E50 (Proto 0x002F1E50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403E78;
extern "C" int DAT_00403E7C;
extern "C" unsigned short DAT_00403E84;
extern "C" unsigned short DAT_00403E86;
extern "C" unsigned short DAT_00403E8A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1E50(void)
{
    DAT_00403E78 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403E7C);
    DAT_00403E7C = 0;
    DAT_00403E84 = 0;
    DAT_00403E86 = 0;
    DAT_00403E8A = 0;
    return 0;
}
