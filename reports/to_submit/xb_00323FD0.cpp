// bin: xb
// va: 0x00323FD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323FD0 (0x00323FD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429630;
extern "C" int DAT_00429634;
extern "C" unsigned short DAT_0042963C;
extern "C" unsigned short DAT_0042963E;
extern "C" unsigned short DAT_00429642;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323FD0(void)
{
    DAT_00429630 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429634);
    DAT_00429634 = 0;
    DAT_0042963C = 0;
    DAT_0042963E = 0;
    DAT_00429642 = 0;
    return 0;
}
