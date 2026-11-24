// bin: xb
// va: 0x00324290
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324290 (0x00324290, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429814;
extern "C" int DAT_00429818;
extern "C" unsigned short DAT_00429820;
extern "C" unsigned short DAT_00429822;
extern "C" unsigned short DAT_00429826;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324290(void)
{
    DAT_00429814 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429818);
    DAT_00429818 = 0;
    DAT_00429820 = 0;
    DAT_00429822 = 0;
    DAT_00429826 = 0;
    return 0;
}
