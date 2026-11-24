// bin: xb
// va: 0x00323A50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323A50 (0x00323A50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429268;
extern "C" int DAT_0042926C;
extern "C" unsigned short DAT_00429274;
extern "C" unsigned short DAT_00429276;
extern "C" unsigned short DAT_0042927A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323A50(void)
{
    DAT_00429268 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042926C);
    DAT_0042926C = 0;
    DAT_00429274 = 0;
    DAT_00429276 = 0;
    DAT_0042927A = 0;
    return 0;
}
