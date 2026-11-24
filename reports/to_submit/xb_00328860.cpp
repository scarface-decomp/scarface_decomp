// bin: xb
// va: 0x00328860
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328860 (0x00328860, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447C48;
extern "C" int DAT_00447C4C;
extern "C" unsigned short DAT_00447C54;
extern "C" unsigned short DAT_00447C56;
extern "C" unsigned short DAT_00447C5A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328860(void)
{
    DAT_00447C48 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447C4C);
    DAT_00447C4C = 0;
    DAT_00447C54 = 0;
    DAT_00447C56 = 0;
    DAT_00447C5A = 0;
    return 0;
}
