// bin: proto
// va: 0x002F3310
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3310 (Proto 0x002F3310, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040C768;
extern "C" int DAT_0040C76C;
extern "C" unsigned short DAT_0040C774;
extern "C" unsigned short DAT_0040C776;
extern "C" unsigned short DAT_0040C77A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3310(void)
{
    DAT_0040C768 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040C76C);
    DAT_0040C76C = 0;
    DAT_0040C774 = 0;
    DAT_0040C776 = 0;
    DAT_0040C77A = 0;
    return 0;
}
