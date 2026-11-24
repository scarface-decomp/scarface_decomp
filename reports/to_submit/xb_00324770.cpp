// bin: xb
// va: 0x00324770
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324770 (0x00324770, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042E334;
extern "C" int DAT_0042E338;
extern "C" unsigned short DAT_0042E340;
extern "C" unsigned short DAT_0042E342;
extern "C" unsigned short DAT_0042E346;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324770(void)
{
    DAT_0042E334 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042E338);
    DAT_0042E338 = 0;
    DAT_0042E340 = 0;
    DAT_0042E342 = 0;
    DAT_0042E346 = 0;
    return 0;
}
