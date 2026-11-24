// bin: xb
// va: 0x00322A30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322A30 (0x00322A30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041B7A8;
extern "C" int DAT_0041B7AC;
extern "C" unsigned short DAT_0041B7B4;
extern "C" unsigned short DAT_0041B7B6;
extern "C" unsigned short DAT_0041B7BA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322A30(void)
{
    DAT_0041B7A8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041B7AC);
    DAT_0041B7AC = 0;
    DAT_0041B7B4 = 0;
    DAT_0041B7B6 = 0;
    DAT_0041B7BA = 0;
    return 0;
}
