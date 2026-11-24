// bin: proto
// va: 0x002F4D40
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4D40 (Proto 0x002F4D40, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00415304;
extern "C" int DAT_00415308;
extern "C" unsigned short DAT_00415310;
extern "C" unsigned short DAT_00415312;
extern "C" unsigned short DAT_00415316;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4D40(void)
{
    DAT_00415304 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00415308);
    DAT_00415308 = 0;
    DAT_00415310 = 0;
    DAT_00415312 = 0;
    DAT_00415316 = 0;
    return 0;
}
