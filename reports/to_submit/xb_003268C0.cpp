// bin: xb
// va: 0x003268C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003268C0 (0x003268C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043B9A8;
extern "C" int DAT_0043B9AC;
extern "C" unsigned short DAT_0043B9B4;
extern "C" unsigned short DAT_0043B9B6;
extern "C" unsigned short DAT_0043B9BA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003268C0(void)
{
    DAT_0043B9A8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043B9AC);
    DAT_0043B9AC = 0;
    DAT_0043B9B4 = 0;
    DAT_0043B9B6 = 0;
    DAT_0043B9BA = 0;
    return 0;
}
