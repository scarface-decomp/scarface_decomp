// bin: proto
// va: 0x002F4720
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4720 (Proto 0x002F4720, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041353C;
extern "C" int DAT_00413540;
extern "C" unsigned short DAT_00413548;
extern "C" unsigned short DAT_0041354A;
extern "C" unsigned short DAT_0041354E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4720(void)
{
    DAT_0041353C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00413540);
    DAT_00413540 = 0;
    DAT_00413548 = 0;
    DAT_0041354A = 0;
    DAT_0041354E = 0;
    return 0;
}
