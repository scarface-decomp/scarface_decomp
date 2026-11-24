// bin: xb
// va: 0x003263D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003263D0 (0x003263D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00439EAC;
extern "C" int DAT_00439EB0;
extern "C" unsigned short DAT_00439EB8;
extern "C" unsigned short DAT_00439EBA;
extern "C" unsigned short DAT_00439EBE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003263D0(void)
{
    DAT_00439EAC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00439EB0);
    DAT_00439EB0 = 0;
    DAT_00439EB8 = 0;
    DAT_00439EBA = 0;
    DAT_00439EBE = 0;
    return 0;
}
