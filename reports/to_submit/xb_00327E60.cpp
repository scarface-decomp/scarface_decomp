// bin: xb
// va: 0x00327E60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327E60 (0x00327E60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00444668;
extern "C" int DAT_0044466C;
extern "C" unsigned short DAT_00444674;
extern "C" unsigned short DAT_00444676;
extern "C" unsigned short DAT_0044467A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327E60(void)
{
    DAT_00444668 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044466C);
    DAT_0044466C = 0;
    DAT_00444674 = 0;
    DAT_00444676 = 0;
    DAT_0044467A = 0;
    return 0;
}
