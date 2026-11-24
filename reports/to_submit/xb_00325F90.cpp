// bin: xb
// va: 0x00325F90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325F90 (0x00325F90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043847C;
extern "C" int DAT_00438480;
extern "C" unsigned short DAT_00438488;
extern "C" unsigned short DAT_0043848A;
extern "C" unsigned short DAT_0043848E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325F90(void)
{
    DAT_0043847C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00438480);
    DAT_00438480 = 0;
    DAT_00438488 = 0;
    DAT_0043848A = 0;
    DAT_0043848E = 0;
    return 0;
}
