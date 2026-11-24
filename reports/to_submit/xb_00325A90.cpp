// bin: xb
// va: 0x00325A90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325A90 (0x00325A90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043725C;
extern "C" int DAT_00437260;
extern "C" unsigned short DAT_00437268;
extern "C" unsigned short DAT_0043726A;
extern "C" unsigned short DAT_0043726E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325A90(void)
{
    DAT_0043725C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00437260);
    DAT_00437260 = 0;
    DAT_00437268 = 0;
    DAT_0043726A = 0;
    DAT_0043726E = 0;
    return 0;
}
