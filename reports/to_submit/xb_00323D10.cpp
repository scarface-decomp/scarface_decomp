// bin: xb
// va: 0x00323D10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323D10 (0x00323D10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042944C;
extern "C" int DAT_00429450;
extern "C" unsigned short DAT_00429458;
extern "C" unsigned short DAT_0042945A;
extern "C" unsigned short DAT_0042945E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323D10(void)
{
    DAT_0042944C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429450);
    DAT_00429450 = 0;
    DAT_00429458 = 0;
    DAT_0042945A = 0;
    DAT_0042945E = 0;
    return 0;
}
