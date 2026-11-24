// bin: xb
// va: 0x003264B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003264B0 (0x003264B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043A54C;
extern "C" int DAT_0043A550;
extern "C" unsigned short DAT_0043A558;
extern "C" unsigned short DAT_0043A55A;
extern "C" unsigned short DAT_0043A55E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003264B0(void)
{
    DAT_0043A54C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043A550);
    DAT_0043A550 = 0;
    DAT_0043A558 = 0;
    DAT_0043A55A = 0;
    DAT_0043A55E = 0;
    return 0;
}
