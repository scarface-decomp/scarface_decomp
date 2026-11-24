// bin: proto
// va: 0x002F2610
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2610 (Proto 0x002F2610, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004043CC;
extern "C" int DAT_004043D0;
extern "C" unsigned short DAT_004043D8;
extern "C" unsigned short DAT_004043DA;
extern "C" unsigned short DAT_004043DE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2610(void)
{
    DAT_004043CC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004043D0);
    DAT_004043D0 = 0;
    DAT_004043D8 = 0;
    DAT_004043DA = 0;
    DAT_004043DE = 0;
    return 0;
}
