// bin: xb
// va: 0x00326B40
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326B40 (0x00326B40, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043D8E8;
extern "C" int DAT_0043D8EC;
extern "C" unsigned short DAT_0043D8F4;
extern "C" unsigned short DAT_0043D8F6;
extern "C" unsigned short DAT_0043D8FA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326B40(void)
{
    DAT_0043D8E8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043D8EC);
    DAT_0043D8EC = 0;
    DAT_0043D8F4 = 0;
    DAT_0043D8F6 = 0;
    DAT_0043D8FA = 0;
    return 0;
}
