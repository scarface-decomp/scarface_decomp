// bin: proto
// va: 0x002F28F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F28F0 (Proto 0x002F28F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409018;
extern "C" int DAT_0040901C;
extern "C" unsigned short DAT_00409024;
extern "C" unsigned short DAT_00409026;
extern "C" unsigned short DAT_0040902A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F28F0(void)
{
    DAT_00409018 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040901C);
    DAT_0040901C = 0;
    DAT_00409024 = 0;
    DAT_00409026 = 0;
    DAT_0040902A = 0;
    return 0;
}
