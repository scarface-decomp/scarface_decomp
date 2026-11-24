// bin: xb
// va: 0x00324C20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324C20 (0x00324C20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004304FC;
extern "C" int DAT_00430500;
extern "C" unsigned short DAT_00430508;
extern "C" unsigned short DAT_0043050A;
extern "C" unsigned short DAT_0043050E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324C20(void)
{
    DAT_004304FC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00430500);
    DAT_00430500 = 0;
    DAT_00430508 = 0;
    DAT_0043050A = 0;
    DAT_0043050E = 0;
    return 0;
}
