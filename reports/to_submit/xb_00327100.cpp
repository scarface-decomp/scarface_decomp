// bin: xb
// va: 0x00327100
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327100 (0x00327100, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043E49C;
extern "C" int DAT_0043E4A0;
extern "C" unsigned short DAT_0043E4A8;
extern "C" unsigned short DAT_0043E4AA;
extern "C" unsigned short DAT_0043E4AE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327100(void)
{
    DAT_0043E49C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043E4A0);
    DAT_0043E4A0 = 0;
    DAT_0043E4A8 = 0;
    DAT_0043E4AA = 0;
    DAT_0043E4AE = 0;
    return 0;
}
