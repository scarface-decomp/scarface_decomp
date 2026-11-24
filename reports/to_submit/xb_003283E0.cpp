// bin: xb
// va: 0x003283E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003283E0 (0x003283E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004478D0;
extern "C" int DAT_004478D4;
extern "C" unsigned short DAT_004478DC;
extern "C" unsigned short DAT_004478DE;
extern "C" unsigned short DAT_004478E2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003283E0(void)
{
    DAT_004478D0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004478D4);
    DAT_004478D4 = 0;
    DAT_004478DC = 0;
    DAT_004478DE = 0;
    DAT_004478E2 = 0;
    return 0;
}
