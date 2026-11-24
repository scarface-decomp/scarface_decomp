// bin: proto
// va: 0x002F5550
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5550 (Proto 0x002F5550, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004179C0;
extern "C" int DAT_004179C4;
extern "C" unsigned short DAT_004179CC;
extern "C" unsigned short DAT_004179CE;
extern "C" unsigned short DAT_004179D2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5550(void)
{
    DAT_004179C0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004179C4);
    DAT_004179C4 = 0;
    DAT_004179CC = 0;
    DAT_004179CE = 0;
    DAT_004179D2 = 0;
    return 0;
}
