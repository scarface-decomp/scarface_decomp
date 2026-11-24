// bin: proto
// va: 0x002F30D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F30D0 (Proto 0x002F30D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040ADA4;
extern "C" int DAT_0040ADA8;
extern "C" unsigned short DAT_0040ADB0;
extern "C" unsigned short DAT_0040ADB2;
extern "C" unsigned short DAT_0040ADB6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F30D0(void)
{
    DAT_0040ADA4 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040ADA8);
    DAT_0040ADA8 = 0;
    DAT_0040ADB0 = 0;
    DAT_0040ADB2 = 0;
    DAT_0040ADB6 = 0;
    return 0;
}
