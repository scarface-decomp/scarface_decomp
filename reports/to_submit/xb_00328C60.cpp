// bin: xb
// va: 0x00328C60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328C60 (0x00328C60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044BA6C;
extern "C" int DAT_0044BA70;
extern "C" unsigned short DAT_0044BA78;
extern "C" unsigned short DAT_0044BA7A;
extern "C" unsigned short DAT_0044BA7E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328C60(void)
{
    DAT_0044BA6C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044BA70);
    DAT_0044BA70 = 0;
    DAT_0044BA78 = 0;
    DAT_0044BA7A = 0;
    DAT_0044BA7E = 0;
    return 0;
}
