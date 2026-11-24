// bin: xb
// va: 0x00324150
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324150 (0x00324150, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429738;
extern "C" int DAT_0042973C;
extern "C" unsigned short DAT_00429744;
extern "C" unsigned short DAT_00429746;
extern "C" unsigned short DAT_0042974A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324150(void)
{
    DAT_00429738 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042973C);
    DAT_0042973C = 0;
    DAT_00429744 = 0;
    DAT_00429746 = 0;
    DAT_0042974A = 0;
    return 0;
}
