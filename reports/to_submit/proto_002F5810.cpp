// bin: proto
// va: 0x002F5810
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5810 (Proto 0x002F5810, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00418754;
extern "C" int DAT_00418758;
extern "C" unsigned short DAT_00418760;
extern "C" unsigned short DAT_00418762;
extern "C" unsigned short DAT_00418766;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5810(void)
{
    DAT_00418754 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00418758);
    DAT_00418758 = 0;
    DAT_00418760 = 0;
    DAT_00418762 = 0;
    DAT_00418766 = 0;
    return 0;
}
