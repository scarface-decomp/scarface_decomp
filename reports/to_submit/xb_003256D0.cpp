// bin: xb
// va: 0x003256D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003256D0 (0x003256D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436AAC;
extern "C" int DAT_00436AB0;
extern "C" unsigned short DAT_00436AB8;
extern "C" unsigned short DAT_00436ABA;
extern "C" unsigned short DAT_00436ABE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003256D0(void)
{
    DAT_00436AAC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436AB0);
    DAT_00436AB0 = 0;
    DAT_00436AB8 = 0;
    DAT_00436ABA = 0;
    DAT_00436ABE = 0;
    return 0;
}
