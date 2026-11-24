// bin: xb
// va: 0x00323E50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323E50 (0x00323E50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429528;
extern "C" int DAT_0042952C;
extern "C" unsigned short DAT_00429534;
extern "C" unsigned short DAT_00429536;
extern "C" unsigned short DAT_0042953A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323E50(void)
{
    DAT_00429528 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042952C);
    DAT_0042952C = 0;
    DAT_00429534 = 0;
    DAT_00429536 = 0;
    DAT_0042953A = 0;
    return 0;
}
