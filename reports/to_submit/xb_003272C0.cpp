// bin: xb
// va: 0x003272C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003272C0 (0x003272C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043EA88;
extern "C" int DAT_0043EA8C;
extern "C" unsigned short DAT_0043EA94;
extern "C" unsigned short DAT_0043EA96;
extern "C" unsigned short DAT_0043EA9A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003272C0(void)
{
    DAT_0043EA88 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043EA8C);
    DAT_0043EA8C = 0;
    DAT_0043EA94 = 0;
    DAT_0043EA96 = 0;
    DAT_0043EA9A = 0;
    return 0;
}
