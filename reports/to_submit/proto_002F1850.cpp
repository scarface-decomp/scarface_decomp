// bin: proto
// va: 0x002F1850
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1850 (Proto 0x002F1850, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004033B0;
extern "C" int DAT_004033B4;
extern "C" unsigned short DAT_004033BC;
extern "C" unsigned short DAT_004033BE;
extern "C" unsigned short DAT_004033C2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1850(void)
{
    DAT_004033B0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004033B4);
    DAT_004033B4 = 0;
    DAT_004033BC = 0;
    DAT_004033BE = 0;
    DAT_004033C2 = 0;
    return 0;
}
