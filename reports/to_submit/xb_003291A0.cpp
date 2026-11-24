// bin: xb
// va: 0x003291A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003291A0 (0x003291A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044D87C;
extern "C" int DAT_0044D880;
extern "C" unsigned short DAT_0044D888;
extern "C" unsigned short DAT_0044D88A;
extern "C" unsigned short DAT_0044D88E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003291A0(void)
{
    DAT_0044D87C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044D880);
    DAT_0044D880 = 0;
    DAT_0044D888 = 0;
    DAT_0044D88A = 0;
    DAT_0044D88E = 0;
    return 0;
}
