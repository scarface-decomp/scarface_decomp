// bin: xb
// va: 0x00327540
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327540 (0x00327540, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043FCE8;
extern "C" int DAT_0043FCEC;
extern "C" unsigned short DAT_0043FCF4;
extern "C" unsigned short DAT_0043FCF6;
extern "C" unsigned short DAT_0043FCFA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327540(void)
{
    DAT_0043FCE8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043FCEC);
    DAT_0043FCEC = 0;
    DAT_0043FCF4 = 0;
    DAT_0043FCF6 = 0;
    DAT_0043FCFA = 0;
    return 0;
}
