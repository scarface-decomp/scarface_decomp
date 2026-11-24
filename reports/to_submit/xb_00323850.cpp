// bin: xb
// va: 0x00323850
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323850 (0x00323850, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429108;
extern "C" int DAT_0042910C;
extern "C" unsigned short DAT_00429114;
extern "C" unsigned short DAT_00429116;
extern "C" unsigned short DAT_0042911A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323850(void)
{
    DAT_00429108 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042910C);
    DAT_0042910C = 0;
    DAT_00429114 = 0;
    DAT_00429116 = 0;
    DAT_0042911A = 0;
    return 0;
}
