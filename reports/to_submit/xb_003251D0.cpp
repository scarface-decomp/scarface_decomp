// bin: xb
// va: 0x003251D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003251D0 (0x003251D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00435F74;
extern "C" int DAT_00435F78;
extern "C" unsigned short DAT_00435F80;
extern "C" unsigned short DAT_00435F82;
extern "C" unsigned short DAT_00435F86;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003251D0(void)
{
    DAT_00435F74 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00435F78);
    DAT_00435F78 = 0;
    DAT_00435F80 = 0;
    DAT_00435F82 = 0;
    DAT_00435F86 = 0;
    return 0;
}
