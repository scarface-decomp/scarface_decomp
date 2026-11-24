// bin: xb
// va: 0x00322BF0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322BF0 (0x00322BF0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041BC30;
extern "C" int DAT_0041BC34;
extern "C" unsigned short DAT_0041BC3C;
extern "C" unsigned short DAT_0041BC3E;
extern "C" unsigned short DAT_0041BC42;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322BF0(void)
{
    DAT_0041BC30 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041BC34);
    DAT_0041BC34 = 0;
    DAT_0041BC3C = 0;
    DAT_0041BC3E = 0;
    DAT_0041BC42 = 0;
    return 0;
}
