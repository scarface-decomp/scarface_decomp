// bin: xb
// va: 0x00322CB0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322CB0 (0x00322CB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041BF9C;
extern "C" int DAT_0041BFA0;
extern "C" unsigned short DAT_0041BFA8;
extern "C" unsigned short DAT_0041BFAA;
extern "C" unsigned short DAT_0041BFAE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322CB0(void)
{
    DAT_0041BF9C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041BFA0);
    DAT_0041BFA0 = 0;
    DAT_0041BFA8 = 0;
    DAT_0041BFAA = 0;
    DAT_0041BFAE = 0;
    return 0;
}
