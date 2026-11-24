// bin: xb
// va: 0x00327CE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327CE0 (0x00327CE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00444020;
extern "C" int DAT_00444024;
extern "C" unsigned short DAT_0044402C;
extern "C" unsigned short DAT_0044402E;
extern "C" unsigned short DAT_00444032;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327CE0(void)
{
    DAT_00444020 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00444024);
    DAT_00444024 = 0;
    DAT_0044402C = 0;
    DAT_0044402E = 0;
    DAT_00444032 = 0;
    return 0;
}
