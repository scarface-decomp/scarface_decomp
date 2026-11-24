// bin: xb
// va: 0x00325990
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325990 (0x00325990, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00437130;
extern "C" int DAT_00437134;
extern "C" unsigned short DAT_0043713C;
extern "C" unsigned short DAT_0043713E;
extern "C" unsigned short DAT_00437142;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325990(void)
{
    DAT_00437130 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00437134);
    DAT_00437134 = 0;
    DAT_0043713C = 0;
    DAT_0043713E = 0;
    DAT_00437142 = 0;
    return 0;
}
