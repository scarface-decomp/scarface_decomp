// bin: xb
// va: 0x00326D00
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326D00 (0x00326D00, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043DA1C;
extern "C" int DAT_0043DA20;
extern "C" unsigned short DAT_0043DA28;
extern "C" unsigned short DAT_0043DA2A;
extern "C" unsigned short DAT_0043DA2E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326D00(void)
{
    DAT_0043DA1C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043DA20);
    DAT_0043DA20 = 0;
    DAT_0043DA28 = 0;
    DAT_0043DA2A = 0;
    DAT_0043DA2E = 0;
    return 0;
}
