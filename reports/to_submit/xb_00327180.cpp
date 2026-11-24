// bin: xb
// va: 0x00327180
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327180 (0x00327180, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043E714;
extern "C" int DAT_0043E718;
extern "C" unsigned short DAT_0043E720;
extern "C" unsigned short DAT_0043E722;
extern "C" unsigned short DAT_0043E726;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327180(void)
{
    DAT_0043E714 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043E718);
    DAT_0043E718 = 0;
    DAT_0043E720 = 0;
    DAT_0043E722 = 0;
    DAT_0043E726 = 0;
    return 0;
}
