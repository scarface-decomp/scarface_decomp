// bin: xb
// va: 0x00326880
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326880 (0x00326880, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043B97C;
extern "C" int DAT_0043B980;
extern "C" unsigned short DAT_0043B988;
extern "C" unsigned short DAT_0043B98A;
extern "C" unsigned short DAT_0043B98E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326880(void)
{
    DAT_0043B97C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043B980);
    DAT_0043B980 = 0;
    DAT_0043B988 = 0;
    DAT_0043B98A = 0;
    DAT_0043B98E = 0;
    return 0;
}
