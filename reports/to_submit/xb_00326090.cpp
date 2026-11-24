// bin: xb
// va: 0x00326090
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326090 (0x00326090, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00438B08;
extern "C" int DAT_00438B0C;
extern "C" unsigned short DAT_00438B14;
extern "C" unsigned short DAT_00438B16;
extern "C" unsigned short DAT_00438B1A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326090(void)
{
    DAT_00438B08 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00438B0C);
    DAT_00438B0C = 0;
    DAT_00438B14 = 0;
    DAT_00438B16 = 0;
    DAT_00438B1A = 0;
    return 0;
}
