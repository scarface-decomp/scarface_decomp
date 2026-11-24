// bin: xb
// va: 0x00327240
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327240 (0x00327240, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043E7D4;
extern "C" int DAT_0043E7D8;
extern "C" unsigned short DAT_0043E7E0;
extern "C" unsigned short DAT_0043E7E2;
extern "C" unsigned short DAT_0043E7E6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327240(void)
{
    DAT_0043E7D4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043E7D8);
    DAT_0043E7D8 = 0;
    DAT_0043E7E0 = 0;
    DAT_0043E7E2 = 0;
    DAT_0043E7E6 = 0;
    return 0;
}
