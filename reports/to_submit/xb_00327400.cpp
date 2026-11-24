// bin: xb
// va: 0x00327400
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327400 (0x00327400, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043FA54;
extern "C" int DAT_0043FA58;
extern "C" unsigned short DAT_0043FA60;
extern "C" unsigned short DAT_0043FA62;
extern "C" unsigned short DAT_0043FA66;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327400(void)
{
    DAT_0043FA54 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043FA58);
    DAT_0043FA58 = 0;
    DAT_0043FA60 = 0;
    DAT_0043FA62 = 0;
    DAT_0043FA66 = 0;
    return 0;
}
