// bin: xb
// va: 0x00324900
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324900 (0x00324900, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042EA4C;
extern "C" int DAT_0042EA50;
extern "C" unsigned short DAT_0042EA58;
extern "C" unsigned short DAT_0042EA5A;
extern "C" unsigned short DAT_0042EA5E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324900(void)
{
    DAT_0042EA4C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042EA50);
    DAT_0042EA50 = 0;
    DAT_0042EA58 = 0;
    DAT_0042EA5A = 0;
    DAT_0042EA5E = 0;
    return 0;
}
