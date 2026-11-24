// bin: xb
// va: 0x00325850
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325850 (0x00325850, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436BB4;
extern "C" int DAT_00436BB8;
extern "C" unsigned short DAT_00436BC0;
extern "C" unsigned short DAT_00436BC2;
extern "C" unsigned short DAT_00436BC6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325850(void)
{
    DAT_00436BB4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436BB8);
    DAT_00436BB8 = 0;
    DAT_00436BC0 = 0;
    DAT_00436BC2 = 0;
    DAT_00436BC6 = 0;
    return 0;
}
