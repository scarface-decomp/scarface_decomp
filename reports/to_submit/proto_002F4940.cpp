// bin: proto
// va: 0x002F4940
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4940 (Proto 0x002F4940, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00413F1C;
extern "C" int DAT_00413F20;
extern "C" unsigned short DAT_00413F28;
extern "C" unsigned short DAT_00413F2A;
extern "C" unsigned short DAT_00413F2E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4940(void)
{
    DAT_00413F1C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00413F20);
    DAT_00413F20 = 0;
    DAT_00413F28 = 0;
    DAT_00413F2A = 0;
    DAT_00413F2E = 0;
    return 0;
}
