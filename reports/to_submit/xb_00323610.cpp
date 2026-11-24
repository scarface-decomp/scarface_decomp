// bin: xb
// va: 0x00323610
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323610 (0x00323610, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00428F7C;
extern "C" int DAT_00428F80;
extern "C" unsigned short DAT_00428F88;
extern "C" unsigned short DAT_00428F8A;
extern "C" unsigned short DAT_00428F8E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323610(void)
{
    DAT_00428F7C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00428F80);
    DAT_00428F80 = 0;
    DAT_00428F88 = 0;
    DAT_00428F8A = 0;
    DAT_00428F8E = 0;
    return 0;
}
