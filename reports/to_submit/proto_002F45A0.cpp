// bin: proto
// va: 0x002F45A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F45A0 (Proto 0x002F45A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00413434;
extern "C" int DAT_00413438;
extern "C" unsigned short DAT_00413440;
extern "C" unsigned short DAT_00413442;
extern "C" unsigned short DAT_00413446;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F45A0(void)
{
    DAT_00413434 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00413438);
    DAT_00413438 = 0;
    DAT_00413440 = 0;
    DAT_00413442 = 0;
    DAT_00413446 = 0;
    return 0;
}
