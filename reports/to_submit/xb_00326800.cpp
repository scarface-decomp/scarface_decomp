// bin: xb
// va: 0x00326800
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326800 (0x00326800, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043B690;
extern "C" int DAT_0043B694;
extern "C" unsigned short DAT_0043B69C;
extern "C" unsigned short DAT_0043B69E;
extern "C" unsigned short DAT_0043B6A2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326800(void)
{
    DAT_0043B690 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043B694);
    DAT_0043B694 = 0;
    DAT_0043B69C = 0;
    DAT_0043B69E = 0;
    DAT_0043B6A2 = 0;
    return 0;
}
