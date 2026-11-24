// bin: xb
// va: 0x00322C30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322C30 (0x00322C30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041BC5C;
extern "C" int DAT_0041BC60;
extern "C" unsigned short DAT_0041BC68;
extern "C" unsigned short DAT_0041BC6A;
extern "C" unsigned short DAT_0041BC6E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322C30(void)
{
    DAT_0041BC5C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041BC60);
    DAT_0041BC60 = 0;
    DAT_0041BC68 = 0;
    DAT_0041BC6A = 0;
    DAT_0041BC6E = 0;
    return 0;
}
