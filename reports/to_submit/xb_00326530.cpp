// bin: xb
// va: 0x00326530
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326530 (0x00326530, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043A85C;
extern "C" int DAT_0043A860;
extern "C" unsigned short DAT_0043A868;
extern "C" unsigned short DAT_0043A86A;
extern "C" unsigned short DAT_0043A86E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326530(void)
{
    DAT_0043A85C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043A860);
    DAT_0043A860 = 0;
    DAT_0043A868 = 0;
    DAT_0043A86A = 0;
    DAT_0043A86E = 0;
    return 0;
}
