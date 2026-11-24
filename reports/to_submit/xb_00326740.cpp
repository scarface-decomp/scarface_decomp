// bin: xb
// va: 0x00326740
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326740 (0x00326740, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043B49C;
extern "C" int DAT_0043B4A0;
extern "C" unsigned short DAT_0043B4A8;
extern "C" unsigned short DAT_0043B4AA;
extern "C" unsigned short DAT_0043B4AE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326740(void)
{
    DAT_0043B49C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043B4A0);
    DAT_0043B4A0 = 0;
    DAT_0043B4A8 = 0;
    DAT_0043B4AA = 0;
    DAT_0043B4AE = 0;
    return 0;
}
