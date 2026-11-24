// bin: xb
// va: 0x00325F50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325F50 (0x00325F50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00438068;
extern "C" int DAT_0043806C;
extern "C" unsigned short DAT_00438074;
extern "C" unsigned short DAT_00438076;
extern "C" unsigned short DAT_0043807A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325F50(void)
{
    DAT_00438068 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043806C);
    DAT_0043806C = 0;
    DAT_00438074 = 0;
    DAT_00438076 = 0;
    DAT_0043807A = 0;
    return 0;
}
