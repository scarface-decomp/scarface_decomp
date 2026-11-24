// bin: xb
// va: 0x00324EE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324EE0 (0x00324EE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00431468;
extern "C" int DAT_0043146C;
extern "C" unsigned short DAT_00431474;
extern "C" unsigned short DAT_00431476;
extern "C" unsigned short DAT_0043147A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324EE0(void)
{
    DAT_00431468 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043146C);
    DAT_0043146C = 0;
    DAT_00431474 = 0;
    DAT_00431476 = 0;
    DAT_0043147A = 0;
    return 0;
}
