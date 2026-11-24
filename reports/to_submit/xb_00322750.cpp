// bin: xb
// va: 0x00322750
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322750 (0x00322750, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041ABE8;
extern "C" int DAT_0041ABEC;
extern "C" unsigned short DAT_0041ABF4;
extern "C" unsigned short DAT_0041ABF6;
extern "C" unsigned short DAT_0041ABFA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322750(void)
{
    DAT_0041ABE8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041ABEC);
    DAT_0041ABEC = 0;
    DAT_0041ABF4 = 0;
    DAT_0041ABF6 = 0;
    DAT_0041ABFA = 0;
    return 0;
}
