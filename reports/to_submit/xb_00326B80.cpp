// bin: xb
// va: 0x00326B80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326B80 (0x00326B80, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043D914;
extern "C" int DAT_0043D918;
extern "C" unsigned short DAT_0043D920;
extern "C" unsigned short DAT_0043D922;
extern "C" unsigned short DAT_0043D926;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326B80(void)
{
    DAT_0043D914 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043D918);
    DAT_0043D918 = 0;
    DAT_0043D920 = 0;
    DAT_0043D922 = 0;
    DAT_0043D926 = 0;
    return 0;
}
