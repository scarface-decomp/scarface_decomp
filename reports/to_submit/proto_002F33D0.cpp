// bin: proto
// va: 0x002F33D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F33D0 (Proto 0x002F33D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040C7EC;
extern "C" int DAT_0040C7F0;
extern "C" unsigned short DAT_0040C7F8;
extern "C" unsigned short DAT_0040C7FA;
extern "C" unsigned short DAT_0040C7FE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F33D0(void)
{
    DAT_0040C7EC = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040C7F0);
    DAT_0040C7F0 = 0;
    DAT_0040C7F8 = 0;
    DAT_0040C7FA = 0;
    DAT_0040C7FE = 0;
    return 0;
}
