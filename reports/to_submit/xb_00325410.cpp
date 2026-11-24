// bin: xb
// va: 0x00325410
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325410 (0x00325410, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436398;
extern "C" int DAT_0043639C;
extern "C" unsigned short DAT_004363A4;
extern "C" unsigned short DAT_004363A6;
extern "C" unsigned short DAT_004363AA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325410(void)
{
    DAT_00436398 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043639C);
    DAT_0043639C = 0;
    DAT_004363A4 = 0;
    DAT_004363A6 = 0;
    DAT_004363AA = 0;
    return 0;
}
