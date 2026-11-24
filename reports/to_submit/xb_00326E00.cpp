// bin: xb
// va: 0x00326E00
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326E00 (0x00326E00, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043DACC;
extern "C" int DAT_0043DAD0;
extern "C" unsigned short DAT_0043DAD8;
extern "C" unsigned short DAT_0043DADA;
extern "C" unsigned short DAT_0043DADE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326E00(void)
{
    DAT_0043DACC = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043DAD0);
    DAT_0043DAD0 = 0;
    DAT_0043DAD8 = 0;
    DAT_0043DADA = 0;
    DAT_0043DADE = 0;
    return 0;
}
