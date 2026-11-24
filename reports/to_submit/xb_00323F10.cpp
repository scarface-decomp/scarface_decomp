// bin: xb
// va: 0x00323F10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323F10 (0x00323F10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004295AC;
extern "C" int DAT_004295B0;
extern "C" unsigned short DAT_004295B8;
extern "C" unsigned short DAT_004295BA;
extern "C" unsigned short DAT_004295BE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323F10(void)
{
    DAT_004295AC = (int)DAT_0039D4E4;
    sub_00027600(DAT_004295B0);
    DAT_004295B0 = 0;
    DAT_004295B8 = 0;
    DAT_004295BA = 0;
    DAT_004295BE = 0;
    return 0;
}
