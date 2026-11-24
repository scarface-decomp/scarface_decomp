// bin: xb
// va: 0x00326980
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326980 (0x00326980, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043BC6C;
extern "C" int DAT_0043BC70;
extern "C" unsigned short DAT_0043BC78;
extern "C" unsigned short DAT_0043BC7A;
extern "C" unsigned short DAT_0043BC7E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326980(void)
{
    DAT_0043BC6C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043BC70);
    DAT_0043BC70 = 0;
    DAT_0043BC78 = 0;
    DAT_0043BC7A = 0;
    DAT_0043BC7E = 0;
    return 0;
}
