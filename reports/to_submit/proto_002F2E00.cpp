// bin: proto
// va: 0x002F2E00
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2E00 (Proto 0x002F2E00, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409ECC;
extern "C" int DAT_00409ED0;
extern "C" unsigned short DAT_00409ED8;
extern "C" unsigned short DAT_00409EDA;
extern "C" unsigned short DAT_00409EDE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2E00(void)
{
    DAT_00409ECC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409ED0);
    DAT_00409ED0 = 0;
    DAT_00409ED8 = 0;
    DAT_00409EDA = 0;
    DAT_00409EDE = 0;
    return 0;
}
