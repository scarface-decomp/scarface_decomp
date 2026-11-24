// bin: xb
// va: 0x00322A70
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322A70 (0x00322A70, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041B86C;
extern "C" int DAT_0041B870;
extern "C" unsigned short DAT_0041B878;
extern "C" unsigned short DAT_0041B87A;
extern "C" unsigned short DAT_0041B87E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322A70(void)
{
    DAT_0041B86C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041B870);
    DAT_0041B870 = 0;
    DAT_0041B878 = 0;
    DAT_0041B87A = 0;
    DAT_0041B87E = 0;
    return 0;
}
