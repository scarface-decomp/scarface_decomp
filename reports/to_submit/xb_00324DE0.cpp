// bin: xb
// va: 0x00324DE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324DE0 (0x00324DE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00430E4C;
extern "C" int DAT_00430E50;
extern "C" unsigned short DAT_00430E58;
extern "C" unsigned short DAT_00430E5A;
extern "C" unsigned short DAT_00430E5E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324DE0(void)
{
    DAT_00430E4C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00430E50);
    DAT_00430E50 = 0;
    DAT_00430E58 = 0;
    DAT_00430E5A = 0;
    DAT_00430E5E = 0;
    return 0;
}
