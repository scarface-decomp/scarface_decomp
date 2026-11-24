// bin: xb
// va: 0x00328420
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328420 (0x00328420, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004478FC;
extern "C" int DAT_00447900;
extern "C" unsigned short DAT_00447908;
extern "C" unsigned short DAT_0044790A;
extern "C" unsigned short DAT_0044790E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328420(void)
{
    DAT_004478FC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447900);
    DAT_00447900 = 0;
    DAT_00447908 = 0;
    DAT_0044790A = 0;
    DAT_0044790E = 0;
    return 0;
}
