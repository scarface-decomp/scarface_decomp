// bin: proto
// va: 0x002F2CB0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2CB0 (Proto 0x002F2CB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004096E0;
extern "C" int DAT_004096E4;
extern "C" unsigned short DAT_004096EC;
extern "C" unsigned short DAT_004096EE;
extern "C" unsigned short DAT_004096F2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2CB0(void)
{
    DAT_004096E0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004096E4);
    DAT_004096E4 = 0;
    DAT_004096EC = 0;
    DAT_004096EE = 0;
    DAT_004096F2 = 0;
    return 0;
}
