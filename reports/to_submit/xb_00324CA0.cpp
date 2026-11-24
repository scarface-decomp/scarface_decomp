// bin: xb
// va: 0x00324CA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324CA0 (0x00324CA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00430D70;
extern "C" int DAT_00430D74;
extern "C" unsigned short DAT_00430D7C;
extern "C" unsigned short DAT_00430D7E;
extern "C" unsigned short DAT_00430D82;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324CA0(void)
{
    DAT_00430D70 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00430D74);
    DAT_00430D74 = 0;
    DAT_00430D7C = 0;
    DAT_00430D7E = 0;
    DAT_00430D82 = 0;
    return 0;
}
