// bin: xb
// va: 0x00327840
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327840 (0x00327840, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00440684;
extern "C" int DAT_00440688;
extern "C" unsigned short DAT_00440690;
extern "C" unsigned short DAT_00440692;
extern "C" unsigned short DAT_00440696;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327840(void)
{
    DAT_00440684 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00440688);
    DAT_00440688 = 0;
    DAT_00440690 = 0;
    DAT_00440692 = 0;
    DAT_00440696 = 0;
    return 0;
}
