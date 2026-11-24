// bin: proto
// va: 0x002F3720
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3720 (Proto 0x002F3720, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040FFA8;
extern "C" int DAT_0040FFAC;
extern "C" unsigned short DAT_0040FFB4;
extern "C" unsigned short DAT_0040FFB6;
extern "C" unsigned short DAT_0040FFBA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3720(void)
{
    DAT_0040FFA8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040FFAC);
    DAT_0040FFAC = 0;
    DAT_0040FFB4 = 0;
    DAT_0040FFB6 = 0;
    DAT_0040FFBA = 0;
    return 0;
}
