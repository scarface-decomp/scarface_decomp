// bin: xb
// va: 0x00323550
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323550 (0x00323550, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00428EF8;
extern "C" int DAT_00428EFC;
extern "C" unsigned short DAT_00428F04;
extern "C" unsigned short DAT_00428F06;
extern "C" unsigned short DAT_00428F0A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323550(void)
{
    DAT_00428EF8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00428EFC);
    DAT_00428EFC = 0;
    DAT_00428F04 = 0;
    DAT_00428F06 = 0;
    DAT_00428F0A = 0;
    return 0;
}
