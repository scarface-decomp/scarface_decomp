// bin: xb
// va: 0x00327880
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327880 (0x00327880, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00440BA8;
extern "C" int DAT_00440BAC;
extern "C" unsigned short DAT_00440BB4;
extern "C" unsigned short DAT_00440BB6;
extern "C" unsigned short DAT_00440BBA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327880(void)
{
    DAT_00440BA8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00440BAC);
    DAT_00440BAC = 0;
    DAT_00440BB4 = 0;
    DAT_00440BB6 = 0;
    DAT_00440BBA = 0;
    return 0;
}
