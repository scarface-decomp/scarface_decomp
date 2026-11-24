// bin: xb
// va: 0x00328660
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328660 (0x00328660, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447AE0;
extern "C" int DAT_00447AE4;
extern "C" unsigned short DAT_00447AEC;
extern "C" unsigned short DAT_00447AEE;
extern "C" unsigned short DAT_00447AF2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328660(void)
{
    DAT_00447AE0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447AE4);
    DAT_00447AE4 = 0;
    DAT_00447AEC = 0;
    DAT_00447AEE = 0;
    DAT_00447AF2 = 0;
    return 0;
}
