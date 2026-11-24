// bin: xb
// va: 0x003235D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003235D0 (0x003235D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00428F50;
extern "C" int DAT_00428F54;
extern "C" unsigned short DAT_00428F5C;
extern "C" unsigned short DAT_00428F5E;
extern "C" unsigned short DAT_00428F62;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003235D0(void)
{
    DAT_00428F50 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00428F54);
    DAT_00428F54 = 0;
    DAT_00428F5C = 0;
    DAT_00428F5E = 0;
    DAT_00428F62 = 0;
    return 0;
}
