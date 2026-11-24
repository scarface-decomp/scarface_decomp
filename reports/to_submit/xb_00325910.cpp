// bin: xb
// va: 0x00325910
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325910 (0x00325910, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436F10;
extern "C" int DAT_00436F14;
extern "C" unsigned short DAT_00436F1C;
extern "C" unsigned short DAT_00436F1E;
extern "C" unsigned short DAT_00436F22;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325910(void)
{
    DAT_00436F10 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436F14);
    DAT_00436F14 = 0;
    DAT_00436F1C = 0;
    DAT_00436F1E = 0;
    DAT_00436F22 = 0;
    return 0;
}
