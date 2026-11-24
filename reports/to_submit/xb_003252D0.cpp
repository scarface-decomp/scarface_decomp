// bin: xb
// va: 0x003252D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003252D0 (0x003252D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436168;
extern "C" int DAT_0043616C;
extern "C" unsigned short DAT_00436174;
extern "C" unsigned short DAT_00436176;
extern "C" unsigned short DAT_0043617A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003252D0(void)
{
    DAT_00436168 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043616C);
    DAT_0043616C = 0;
    DAT_00436174 = 0;
    DAT_00436176 = 0;
    DAT_0043617A = 0;
    return 0;
}
