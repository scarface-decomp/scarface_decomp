// bin: xb
// va: 0x00327000
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327000 (0x00327000, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043DC2C;
extern "C" int DAT_0043DC30;
extern "C" unsigned short DAT_0043DC38;
extern "C" unsigned short DAT_0043DC3A;
extern "C" unsigned short DAT_0043DC3E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327000(void)
{
    DAT_0043DC2C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043DC30);
    DAT_0043DC30 = 0;
    DAT_0043DC38 = 0;
    DAT_0043DC3A = 0;
    DAT_0043DC3E = 0;
    return 0;
}
