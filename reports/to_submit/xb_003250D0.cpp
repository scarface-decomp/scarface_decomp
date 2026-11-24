// bin: xb
// va: 0x003250D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003250D0 (0x003250D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00433FB0;
extern "C" int DAT_00433FB4;
extern "C" unsigned short DAT_00433FBC;
extern "C" unsigned short DAT_00433FBE;
extern "C" unsigned short DAT_00433FC2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003250D0(void)
{
    DAT_00433FB0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00433FB4);
    DAT_00433FB4 = 0;
    DAT_00433FBC = 0;
    DAT_00433FBE = 0;
    DAT_00433FC2 = 0;
    return 0;
}
