// bin: proto
// va: 0x002F21D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F21D0 (Proto 0x002F21D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004040E0;
extern "C" int DAT_004040E4;
extern "C" unsigned short DAT_004040EC;
extern "C" unsigned short DAT_004040EE;
extern "C" unsigned short DAT_004040F2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F21D0(void)
{
    DAT_004040E0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004040E4);
    DAT_004040E4 = 0;
    DAT_004040EC = 0;
    DAT_004040EE = 0;
    DAT_004040F2 = 0;
    return 0;
}
