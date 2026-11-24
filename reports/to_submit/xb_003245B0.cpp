// bin: xb
// va: 0x003245B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003245B0 (0x003245B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042E0D8;
extern "C" int DAT_0042E0DC;
extern "C" unsigned short DAT_0042E0E4;
extern "C" unsigned short DAT_0042E0E6;
extern "C" unsigned short DAT_0042E0EA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003245B0(void)
{
    DAT_0042E0D8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042E0DC);
    DAT_0042E0DC = 0;
    DAT_0042E0E4 = 0;
    DAT_0042E0E6 = 0;
    DAT_0042E0EA = 0;
    return 0;
}
