// bin: xb
// va: 0x003275C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003275C0 (0x003275C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043FF94;
extern "C" int DAT_0043FF98;
extern "C" unsigned short DAT_0043FFA0;
extern "C" unsigned short DAT_0043FFA2;
extern "C" unsigned short DAT_0043FFA6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003275C0(void)
{
    DAT_0043FF94 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043FF98);
    DAT_0043FF98 = 0;
    DAT_0043FFA0 = 0;
    DAT_0043FFA2 = 0;
    DAT_0043FFA6 = 0;
    return 0;
}
