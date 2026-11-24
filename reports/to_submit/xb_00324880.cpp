// bin: xb
// va: 0x00324880
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324880 (0x00324880, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042E7D4;
extern "C" int DAT_0042E7D8;
extern "C" unsigned short DAT_0042E7E0;
extern "C" unsigned short DAT_0042E7E2;
extern "C" unsigned short DAT_0042E7E6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324880(void)
{
    DAT_0042E7D4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042E7D8);
    DAT_0042E7D8 = 0;
    DAT_0042E7E0 = 0;
    DAT_0042E7E2 = 0;
    DAT_0042E7E6 = 0;
    return 0;
}
