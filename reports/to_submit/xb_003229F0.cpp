// bin: xb
// va: 0x003229F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003229F0 (0x003229F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041B6B4;
extern "C" int DAT_0041B6B8;
extern "C" unsigned short DAT_0041B6C0;
extern "C" unsigned short DAT_0041B6C2;
extern "C" unsigned short DAT_0041B6C6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003229F0(void)
{
    DAT_0041B6B4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041B6B8);
    DAT_0041B6B8 = 0;
    DAT_0041B6C0 = 0;
    DAT_0041B6C2 = 0;
    DAT_0041B6C6 = 0;
    return 0;
}
