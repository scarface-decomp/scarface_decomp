// bin: xb
// va: 0x003278C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003278C0 (0x003278C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00440CC8;
extern "C" int DAT_00440CCC;
extern "C" unsigned short DAT_00440CD4;
extern "C" unsigned short DAT_00440CD6;
extern "C" unsigned short DAT_00440CDA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003278C0(void)
{
    DAT_00440CC8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00440CCC);
    DAT_00440CCC = 0;
    DAT_00440CD4 = 0;
    DAT_00440CD6 = 0;
    DAT_00440CDA = 0;
    return 0;
}
