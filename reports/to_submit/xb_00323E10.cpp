// bin: xb
// va: 0x00323E10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323E10 (0x00323E10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004294FC;
extern "C" int DAT_00429500;
extern "C" unsigned short DAT_00429508;
extern "C" unsigned short DAT_0042950A;
extern "C" unsigned short DAT_0042950E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323E10(void)
{
    DAT_004294FC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429500);
    DAT_00429500 = 0;
    DAT_00429508 = 0;
    DAT_0042950A = 0;
    DAT_0042950E = 0;
    return 0;
}
