// bin: xb
// va: 0x00325390
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325390 (0x00325390, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004362FC;
extern "C" int DAT_00436300;
extern "C" unsigned short DAT_00436308;
extern "C" unsigned short DAT_0043630A;
extern "C" unsigned short DAT_0043630E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325390(void)
{
    DAT_004362FC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436300);
    DAT_00436300 = 0;
    DAT_00436308 = 0;
    DAT_0043630A = 0;
    DAT_0043630E = 0;
    return 0;
}
