// bin: xb
// va: 0x00324010
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324010 (0x00324010, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042965C;
extern "C" int DAT_00429660;
extern "C" unsigned short DAT_00429668;
extern "C" unsigned short DAT_0042966A;
extern "C" unsigned short DAT_0042966E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324010(void)
{
    DAT_0042965C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429660);
    DAT_00429660 = 0;
    DAT_00429668 = 0;
    DAT_0042966A = 0;
    DAT_0042966E = 0;
    return 0;
}
