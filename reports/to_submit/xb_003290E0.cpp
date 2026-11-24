// bin: xb
// va: 0x003290E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003290E0 (0x003290E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044D518;
extern "C" int DAT_0044D51C;
extern "C" unsigned short DAT_0044D524;
extern "C" unsigned short DAT_0044D526;
extern "C" unsigned short DAT_0044D52A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003290E0(void)
{
    DAT_0044D518 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044D51C);
    DAT_0044D51C = 0;
    DAT_0044D524 = 0;
    DAT_0044D526 = 0;
    DAT_0044D52A = 0;
    return 0;
}
