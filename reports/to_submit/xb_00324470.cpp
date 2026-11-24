// bin: xb
// va: 0x00324470
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324470 (0x00324470, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042DDE0;
extern "C" int DAT_0042DDE4;
extern "C" unsigned short DAT_0042DDEC;
extern "C" unsigned short DAT_0042DDEE;
extern "C" unsigned short DAT_0042DDF2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324470(void)
{
    DAT_0042DDE0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042DDE4);
    DAT_0042DDE4 = 0;
    DAT_0042DDEC = 0;
    DAT_0042DDEE = 0;
    DAT_0042DDF2 = 0;
    return 0;
}
