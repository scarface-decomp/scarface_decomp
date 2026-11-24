// bin: xb
// va: 0x00327280
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327280 (0x00327280, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043E818;
extern "C" int DAT_0043E81C;
extern "C" unsigned short DAT_0043E824;
extern "C" unsigned short DAT_0043E826;
extern "C" unsigned short DAT_0043E82A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327280(void)
{
    DAT_0043E818 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043E81C);
    DAT_0043E81C = 0;
    DAT_0043E824 = 0;
    DAT_0043E826 = 0;
    DAT_0043E82A = 0;
    return 0;
}
