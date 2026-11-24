// bin: xb
// va: 0x00326C00
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326C00 (0x00326C00, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043D96C;
extern "C" int DAT_0043D970;
extern "C" unsigned short DAT_0043D978;
extern "C" unsigned short DAT_0043D97A;
extern "C" unsigned short DAT_0043D97E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326C00(void)
{
    DAT_0043D96C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043D970);
    DAT_0043D970 = 0;
    DAT_0043D978 = 0;
    DAT_0043D97A = 0;
    DAT_0043D97E = 0;
    return 0;
}
