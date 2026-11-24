// bin: xb
// va: 0x00324CE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324CE0 (0x00324CE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00430D9C;
extern "C" int DAT_00430DA0;
extern "C" unsigned short DAT_00430DA8;
extern "C" unsigned short DAT_00430DAA;
extern "C" unsigned short DAT_00430DAE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324CE0(void)
{
    DAT_00430D9C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00430DA0);
    DAT_00430DA0 = 0;
    DAT_00430DA8 = 0;
    DAT_00430DAA = 0;
    DAT_00430DAE = 0;
    return 0;
}
