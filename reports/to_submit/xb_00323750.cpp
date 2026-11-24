// bin: xb
// va: 0x00323750
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323750 (0x00323750, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429058;
extern "C" int DAT_0042905C;
extern "C" unsigned short DAT_00429064;
extern "C" unsigned short DAT_00429066;
extern "C" unsigned short DAT_0042906A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323750(void)
{
    DAT_00429058 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042905C);
    DAT_0042905C = 0;
    DAT_00429064 = 0;
    DAT_00429066 = 0;
    DAT_0042906A = 0;
    return 0;
}
