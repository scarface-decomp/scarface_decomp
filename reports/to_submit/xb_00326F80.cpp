// bin: xb
// va: 0x00326F80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326F80 (0x00326F80, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043DBD4;
extern "C" int DAT_0043DBD8;
extern "C" unsigned short DAT_0043DBE0;
extern "C" unsigned short DAT_0043DBE2;
extern "C" unsigned short DAT_0043DBE6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326F80(void)
{
    DAT_0043DBD4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043DBD8);
    DAT_0043DBD8 = 0;
    DAT_0043DBE0 = 0;
    DAT_0043DBE2 = 0;
    DAT_0043DBE6 = 0;
    return 0;
}
