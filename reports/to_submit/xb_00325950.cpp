// bin: xb
// va: 0x00325950
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325950 (0x00325950, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436F78;
extern "C" int DAT_00436F7C;
extern "C" unsigned short DAT_00436F84;
extern "C" unsigned short DAT_00436F86;
extern "C" unsigned short DAT_00436F8A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325950(void)
{
    DAT_00436F78 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436F7C);
    DAT_00436F7C = 0;
    DAT_00436F84 = 0;
    DAT_00436F86 = 0;
    DAT_00436F8A = 0;
    return 0;
}
