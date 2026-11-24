// bin: proto
// va: 0x002F28B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F28B0 (Proto 0x002F28B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00408FDC;
extern "C" int DAT_00408FE0;
extern "C" unsigned short DAT_00408FE8;
extern "C" unsigned short DAT_00408FEA;
extern "C" unsigned short DAT_00408FEE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F28B0(void)
{
    DAT_00408FDC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00408FE0);
    DAT_00408FE0 = 0;
    DAT_00408FE8 = 0;
    DAT_00408FEA = 0;
    DAT_00408FEE = 0;
    return 0;
}
