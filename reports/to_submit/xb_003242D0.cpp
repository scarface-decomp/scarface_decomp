// bin: xb
// va: 0x003242D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003242D0 (0x003242D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042B010;
extern "C" int DAT_0042B014;
extern "C" unsigned short DAT_0042B01C;
extern "C" unsigned short DAT_0042B01E;
extern "C" unsigned short DAT_0042B022;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003242D0(void)
{
    DAT_0042B010 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042B014);
    DAT_0042B014 = 0;
    DAT_0042B01C = 0;
    DAT_0042B01E = 0;
    DAT_0042B022 = 0;
    return 0;
}
