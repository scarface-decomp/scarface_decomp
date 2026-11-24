// bin: xb
// va: 0x00328A20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328A20 (0x00328A20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044AC60;
extern "C" int DAT_0044AC64;
extern "C" unsigned short DAT_0044AC6C;
extern "C" unsigned short DAT_0044AC6E;
extern "C" unsigned short DAT_0044AC72;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328A20(void)
{
    DAT_0044AC60 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044AC64);
    DAT_0044AC64 = 0;
    DAT_0044AC6C = 0;
    DAT_0044AC6E = 0;
    DAT_0044AC72 = 0;
    return 0;
}
