// bin: proto
// va: 0x002F1580
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1580 (Proto 0x002F1580, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003FF558;
extern "C" int DAT_003FF55C;
extern "C" unsigned short DAT_003FF564;
extern "C" unsigned short DAT_003FF566;
extern "C" unsigned short DAT_003FF56A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1580(void)
{
    DAT_003FF558 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003FF55C);
    DAT_003FF55C = 0;
    DAT_003FF564 = 0;
    DAT_003FF566 = 0;
    DAT_003FF56A = 0;
    return 0;
}
