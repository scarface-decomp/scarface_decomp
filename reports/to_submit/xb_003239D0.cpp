// bin: xb
// va: 0x003239D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003239D0 (0x003239D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429210;
extern "C" int DAT_00429214;
extern "C" unsigned short DAT_0042921C;
extern "C" unsigned short DAT_0042921E;
extern "C" unsigned short DAT_00429222;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003239D0(void)
{
    DAT_00429210 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429214);
    DAT_00429214 = 0;
    DAT_0042921C = 0;
    DAT_0042921E = 0;
    DAT_00429222 = 0;
    return 0;
}
