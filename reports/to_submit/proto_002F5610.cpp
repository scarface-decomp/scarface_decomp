// bin: proto
// va: 0x002F5610
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5610 (Proto 0x002F5610, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417EBC;
extern "C" int DAT_00417EC0;
extern "C" unsigned short DAT_00417EC8;
extern "C" unsigned short DAT_00417ECA;
extern "C" unsigned short DAT_00417ECE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5610(void)
{
    DAT_00417EBC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417EC0);
    DAT_00417EC0 = 0;
    DAT_00417EC8 = 0;
    DAT_00417ECA = 0;
    DAT_00417ECE = 0;
    return 0;
}
