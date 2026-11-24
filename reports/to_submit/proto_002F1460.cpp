// bin: proto
// va: 0x002F1460
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1460 (Proto 0x002F1460, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003FE348;
extern "C" int DAT_003FE34C;
extern "C" unsigned short DAT_003FE354;
extern "C" unsigned short DAT_003FE356;
extern "C" unsigned short DAT_003FE35A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1460(void)
{
    DAT_003FE348 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003FE34C);
    DAT_003FE34C = 0;
    DAT_003FE354 = 0;
    DAT_003FE356 = 0;
    DAT_003FE35A = 0;
    return 0;
}
