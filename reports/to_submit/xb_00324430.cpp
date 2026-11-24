// bin: xb
// va: 0x00324430
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324430 (0x00324430, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042DDA4;
extern "C" int DAT_0042DDA8;
extern "C" unsigned short DAT_0042DDB0;
extern "C" unsigned short DAT_0042DDB2;
extern "C" unsigned short DAT_0042DDB6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324430(void)
{
    DAT_0042DDA4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042DDA8);
    DAT_0042DDA8 = 0;
    DAT_0042DDB0 = 0;
    DAT_0042DDB2 = 0;
    DAT_0042DDB6 = 0;
    return 0;
}
