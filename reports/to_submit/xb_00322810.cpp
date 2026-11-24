// bin: xb
// va: 0x00322810
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322810 (0x00322810, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041AC6C;
extern "C" int DAT_0041AC70;
extern "C" unsigned short DAT_0041AC78;
extern "C" unsigned short DAT_0041AC7A;
extern "C" unsigned short DAT_0041AC7E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322810(void)
{
    DAT_0041AC6C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041AC70);
    DAT_0041AC70 = 0;
    DAT_0041AC78 = 0;
    DAT_0041AC7A = 0;
    DAT_0041AC7E = 0;
    return 0;
}
