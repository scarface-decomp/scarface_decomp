// bin: proto
// va: 0x002F47A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F47A0 (Proto 0x002F47A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00413594;
extern "C" int DAT_00413598;
extern "C" unsigned short DAT_004135A0;
extern "C" unsigned short DAT_004135A2;
extern "C" unsigned short DAT_004135A6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F47A0(void)
{
    DAT_00413594 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00413598);
    DAT_00413598 = 0;
    DAT_004135A0 = 0;
    DAT_004135A2 = 0;
    DAT_004135A6 = 0;
    return 0;
}
