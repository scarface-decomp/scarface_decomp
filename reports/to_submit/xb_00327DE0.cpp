// bin: xb
// va: 0x00327DE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327DE0 (0x00327DE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00444584;
extern "C" int DAT_00444588;
extern "C" unsigned short DAT_00444590;
extern "C" unsigned short DAT_00444592;
extern "C" unsigned short DAT_00444596;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327DE0(void)
{
    DAT_00444584 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00444588);
    DAT_00444588 = 0;
    DAT_00444590 = 0;
    DAT_00444592 = 0;
    DAT_00444596 = 0;
    return 0;
}
