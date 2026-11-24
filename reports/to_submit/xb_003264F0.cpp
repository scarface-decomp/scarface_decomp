// bin: xb
// va: 0x003264F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003264F0 (0x003264F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043A730;
extern "C" int DAT_0043A734;
extern "C" unsigned short DAT_0043A73C;
extern "C" unsigned short DAT_0043A73E;
extern "C" unsigned short DAT_0043A742;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003264F0(void)
{
    DAT_0043A730 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043A734);
    DAT_0043A734 = 0;
    DAT_0043A73C = 0;
    DAT_0043A73E = 0;
    DAT_0043A742 = 0;
    return 0;
}
