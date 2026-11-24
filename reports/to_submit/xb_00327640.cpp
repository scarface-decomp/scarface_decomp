// bin: xb
// va: 0x00327640
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327640 (0x00327640, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00440180;
extern "C" int DAT_00440184;
extern "C" unsigned short DAT_0044018C;
extern "C" unsigned short DAT_0044018E;
extern "C" unsigned short DAT_00440192;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327640(void)
{
    DAT_00440180 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00440184);
    DAT_00440184 = 0;
    DAT_0044018C = 0;
    DAT_0044018E = 0;
    DAT_00440192 = 0;
    return 0;
}
