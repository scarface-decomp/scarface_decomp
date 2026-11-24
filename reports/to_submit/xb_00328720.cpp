// bin: xb
// va: 0x00328720
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328720 (0x00328720, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447B6C;
extern "C" int DAT_00447B70;
extern "C" unsigned short DAT_00447B78;
extern "C" unsigned short DAT_00447B7A;
extern "C" unsigned short DAT_00447B7E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328720(void)
{
    DAT_00447B6C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447B70);
    DAT_00447B70 = 0;
    DAT_00447B78 = 0;
    DAT_00447B7A = 0;
    DAT_00447B7E = 0;
    return 0;
}
