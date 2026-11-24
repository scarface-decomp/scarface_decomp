// bin: xb
// va: 0x00327500
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327500 (0x00327500, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043FB04;
extern "C" int DAT_0043FB08;
extern "C" unsigned short DAT_0043FB10;
extern "C" unsigned short DAT_0043FB12;
extern "C" unsigned short DAT_0043FB16;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327500(void)
{
    DAT_0043FB04 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043FB08);
    DAT_0043FB08 = 0;
    DAT_0043FB10 = 0;
    DAT_0043FB12 = 0;
    DAT_0043FB16 = 0;
    return 0;
}
