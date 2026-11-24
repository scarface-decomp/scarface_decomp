// bin: xb
// va: 0x00324730
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324730 (0x00324730, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042E2AC;
extern "C" int DAT_0042E2B0;
extern "C" unsigned short DAT_0042E2B8;
extern "C" unsigned short DAT_0042E2BA;
extern "C" unsigned short DAT_0042E2BE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324730(void)
{
    DAT_0042E2AC = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042E2B0);
    DAT_0042E2B0 = 0;
    DAT_0042E2B8 = 0;
    DAT_0042E2BA = 0;
    DAT_0042E2BE = 0;
    return 0;
}
