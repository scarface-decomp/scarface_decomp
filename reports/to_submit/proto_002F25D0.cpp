// bin: proto
// va: 0x002F25D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F25D0 (Proto 0x002F25D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004043A0;
extern "C" int DAT_004043A4;
extern "C" unsigned short DAT_004043AC;
extern "C" unsigned short DAT_004043AE;
extern "C" unsigned short DAT_004043B2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F25D0(void)
{
    DAT_004043A0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004043A4);
    DAT_004043A4 = 0;
    DAT_004043AC = 0;
    DAT_004043AE = 0;
    DAT_004043B2 = 0;
    return 0;
}
