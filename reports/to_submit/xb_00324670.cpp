// bin: xb
// va: 0x00324670
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324670 (0x00324670, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042E15C;
extern "C" int DAT_0042E160;
extern "C" unsigned short DAT_0042E168;
extern "C" unsigned short DAT_0042E16A;
extern "C" unsigned short DAT_0042E16E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324670(void)
{
    DAT_0042E15C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042E160);
    DAT_0042E160 = 0;
    DAT_0042E168 = 0;
    DAT_0042E16A = 0;
    DAT_0042E16E = 0;
    return 0;
}
