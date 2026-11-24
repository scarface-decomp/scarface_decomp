// bin: xb
// va: 0x00322650
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322650 (0x00322650, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041AB38;
extern "C" int DAT_0041AB3C;
extern "C" unsigned short DAT_0041AB44;
extern "C" unsigned short DAT_0041AB46;
extern "C" unsigned short DAT_0041AB4A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322650(void)
{
    DAT_0041AB38 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041AB3C);
    DAT_0041AB3C = 0;
    DAT_0041AB44 = 0;
    DAT_0041AB46 = 0;
    DAT_0041AB4A = 0;
    return 0;
}
