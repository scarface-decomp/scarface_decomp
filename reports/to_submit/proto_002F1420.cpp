// bin: proto
// va: 0x002F1420
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1420 (Proto 0x002F1420, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003FE31C;
extern "C" int DAT_003FE320;
extern "C" unsigned short DAT_003FE328;
extern "C" unsigned short DAT_003FE32A;
extern "C" unsigned short DAT_003FE32E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1420(void)
{
    DAT_003FE31C = (int)DAT_0037CCF4;
    sub_00025160(DAT_003FE320);
    DAT_003FE320 = 0;
    DAT_003FE328 = 0;
    DAT_003FE32A = 0;
    DAT_003FE32E = 0;
    return 0;
}
