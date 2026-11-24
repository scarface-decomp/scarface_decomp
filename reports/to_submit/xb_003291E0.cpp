// bin: xb
// va: 0x003291E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003291E0 (0x003291E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044DD70;
extern "C" int DAT_0044DD74;
extern "C" unsigned short DAT_0044DD7C;
extern "C" unsigned short DAT_0044DD7E;
extern "C" unsigned short DAT_0044DD82;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003291E0(void)
{
    DAT_0044DD70 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044DD74);
    DAT_0044DD74 = 0;
    DAT_0044DD7C = 0;
    DAT_0044DD7E = 0;
    DAT_0044DD82 = 0;
    return 0;
}
