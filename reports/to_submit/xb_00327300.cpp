// bin: xb
// va: 0x00327300
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327300 (0x00327300, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043EAB4;
extern "C" int DAT_0043EAB8;
extern "C" unsigned short DAT_0043EAC0;
extern "C" unsigned short DAT_0043EAC2;
extern "C" unsigned short DAT_0043EAC6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327300(void)
{
    DAT_0043EAB4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043EAB8);
    DAT_0043EAB8 = 0;
    DAT_0043EAC0 = 0;
    DAT_0043EAC2 = 0;
    DAT_0043EAC6 = 0;
    return 0;
}
