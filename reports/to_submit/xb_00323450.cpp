// bin: xb
// va: 0x00323450
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323450 (0x00323450, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00428970;
extern "C" int DAT_00428974;
extern "C" unsigned short DAT_0042897C;
extern "C" unsigned short DAT_0042897E;
extern "C" unsigned short DAT_00428982;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323450(void)
{
    DAT_00428970 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00428974);
    DAT_00428974 = 0;
    DAT_0042897C = 0;
    DAT_0042897E = 0;
    DAT_00428982 = 0;
    return 0;
}
