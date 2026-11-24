// bin: xb
// va: 0x00327080
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327080 (0x00327080, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043E0E4;
extern "C" int DAT_0043E0E8;
extern "C" unsigned short DAT_0043E0F0;
extern "C" unsigned short DAT_0043E0F2;
extern "C" unsigned short DAT_0043E0F6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327080(void)
{
    DAT_0043E0E4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043E0E8);
    DAT_0043E0E8 = 0;
    DAT_0043E0F0 = 0;
    DAT_0043E0F2 = 0;
    DAT_0043E0F6 = 0;
    return 0;
}
