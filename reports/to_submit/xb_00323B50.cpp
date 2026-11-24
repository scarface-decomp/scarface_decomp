// bin: xb
// va: 0x00323B50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323B50 (0x00323B50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429318;
extern "C" int DAT_0042931C;
extern "C" unsigned short DAT_00429324;
extern "C" unsigned short DAT_00429326;
extern "C" unsigned short DAT_0042932A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323B50(void)
{
    DAT_00429318 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042931C);
    DAT_0042931C = 0;
    DAT_00429324 = 0;
    DAT_00429326 = 0;
    DAT_0042932A = 0;
    return 0;
}
