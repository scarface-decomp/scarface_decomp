// bin: xb
// va: 0x003271C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003271C0 (0x003271C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043E740;
extern "C" int DAT_0043E744;
extern "C" unsigned short DAT_0043E74C;
extern "C" unsigned short DAT_0043E74E;
extern "C" unsigned short DAT_0043E752;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003271C0(void)
{
    DAT_0043E740 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043E744);
    DAT_0043E744 = 0;
    DAT_0043E74C = 0;
    DAT_0043E74E = 0;
    DAT_0043E752 = 0;
    return 0;
}
