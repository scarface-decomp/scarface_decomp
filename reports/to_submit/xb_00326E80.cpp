// bin: xb
// va: 0x00326E80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326E80 (0x00326E80, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043DB24;
extern "C" int DAT_0043DB28;
extern "C" unsigned short DAT_0043DB30;
extern "C" unsigned short DAT_0043DB32;
extern "C" unsigned short DAT_0043DB36;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326E80(void)
{
    DAT_0043DB24 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043DB28);
    DAT_0043DB28 = 0;
    DAT_0043DB30 = 0;
    DAT_0043DB32 = 0;
    DAT_0043DB36 = 0;
    return 0;
}
