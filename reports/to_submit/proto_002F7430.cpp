// bin: proto
// va: 0x002F7430
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7430 (Proto 0x002F7430, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00425CBC;
extern "C" int DAT_00425CC0;
extern "C" unsigned short DAT_00425CC8;
extern "C" unsigned short DAT_00425CCA;
extern "C" unsigned short DAT_00425CCE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F7430(void)
{
    DAT_00425CBC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00425CC0);
    DAT_00425CC0 = 0;
    DAT_00425CC8 = 0;
    DAT_00425CCA = 0;
    DAT_00425CCE = 0;
    return 0;
}
