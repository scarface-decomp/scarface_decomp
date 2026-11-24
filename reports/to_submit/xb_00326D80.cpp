// bin: xb
// va: 0x00326D80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326D80 (0x00326D80, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043DA74;
extern "C" int DAT_0043DA78;
extern "C" unsigned short DAT_0043DA80;
extern "C" unsigned short DAT_0043DA82;
extern "C" unsigned short DAT_0043DA86;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326D80(void)
{
    DAT_0043DA74 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043DA78);
    DAT_0043DA78 = 0;
    DAT_0043DA80 = 0;
    DAT_0043DA82 = 0;
    DAT_0043DA86 = 0;
    return 0;
}
