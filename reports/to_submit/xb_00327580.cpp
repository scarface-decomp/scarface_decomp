// bin: xb
// va: 0x00327580
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327580 (0x00327580, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043FD90;
extern "C" int DAT_0043FD94;
extern "C" unsigned short DAT_0043FD9C;
extern "C" unsigned short DAT_0043FD9E;
extern "C" unsigned short DAT_0043FDA2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327580(void)
{
    DAT_0043FD90 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043FD94);
    DAT_0043FD94 = 0;
    DAT_0043FD9C = 0;
    DAT_0043FD9E = 0;
    DAT_0043FDA2 = 0;
    return 0;
}
