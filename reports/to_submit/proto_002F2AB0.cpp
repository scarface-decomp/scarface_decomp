// bin: proto
// va: 0x002F2AB0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2AB0 (Proto 0x002F2AB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004093BC;
extern "C" int DAT_004093C0;
extern "C" unsigned short DAT_004093C8;
extern "C" unsigned short DAT_004093CA;
extern "C" unsigned short DAT_004093CE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2AB0(void)
{
    DAT_004093BC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004093C0);
    DAT_004093C0 = 0;
    DAT_004093C8 = 0;
    DAT_004093CA = 0;
    DAT_004093CE = 0;
    return 0;
}
