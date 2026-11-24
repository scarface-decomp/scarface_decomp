// bin: xb
// va: 0x00322B70
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322B70 (0x00322B70, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041BB30;
extern "C" int DAT_0041BB34;
extern "C" unsigned short DAT_0041BB3C;
extern "C" unsigned short DAT_0041BB3E;
extern "C" unsigned short DAT_0041BB42;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322B70(void)
{
    DAT_0041BB30 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041BB34);
    DAT_0041BB34 = 0;
    DAT_0041BB3C = 0;
    DAT_0041BB3E = 0;
    DAT_0041BB42 = 0;
    return 0;
}
