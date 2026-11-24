// bin: xb
// va: 0x00327EE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327EE0 (0x00327EE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004446C0;
extern "C" int DAT_004446C4;
extern "C" unsigned short DAT_004446CC;
extern "C" unsigned short DAT_004446CE;
extern "C" unsigned short DAT_004446D2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327EE0(void)
{
    DAT_004446C0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004446C4);
    DAT_004446C4 = 0;
    DAT_004446CC = 0;
    DAT_004446CE = 0;
    DAT_004446D2 = 0;
    return 0;
}
