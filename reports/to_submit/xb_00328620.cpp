// bin: xb
// va: 0x00328620
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328620 (0x00328620, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447AB4;
extern "C" int DAT_00447AB8;
extern "C" unsigned short DAT_00447AC0;
extern "C" unsigned short DAT_00447AC2;
extern "C" unsigned short DAT_00447AC6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328620(void)
{
    DAT_00447AB4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447AB8);
    DAT_00447AB8 = 0;
    DAT_00447AC0 = 0;
    DAT_00447AC2 = 0;
    DAT_00447AC6 = 0;
    return 0;
}
