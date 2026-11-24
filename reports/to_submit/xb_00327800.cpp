// bin: xb
// va: 0x00327800
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327800 (0x00327800, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00440614;
extern "C" int DAT_00440618;
extern "C" unsigned short DAT_00440620;
extern "C" unsigned short DAT_00440622;
extern "C" unsigned short DAT_00440626;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327800(void)
{
    DAT_00440614 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00440618);
    DAT_00440618 = 0;
    DAT_00440620 = 0;
    DAT_00440622 = 0;
    DAT_00440626 = 0;
    return 0;
}
