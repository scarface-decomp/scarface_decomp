// bin: xb
// va: 0x00324C60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324C60 (0x00324C60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00430D44;
extern "C" int DAT_00430D48;
extern "C" unsigned short DAT_00430D50;
extern "C" unsigned short DAT_00430D52;
extern "C" unsigned short DAT_00430D56;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324C60(void)
{
    DAT_00430D44 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00430D48);
    DAT_00430D48 = 0;
    DAT_00430D50 = 0;
    DAT_00430D52 = 0;
    DAT_00430D56 = 0;
    return 0;
}
