// bin: xb
// va: 0x003289A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003289A0 (0x003289A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004497E8;
extern "C" int DAT_004497EC;
extern "C" unsigned short DAT_004497F4;
extern "C" unsigned short DAT_004497F6;
extern "C" unsigned short DAT_004497FA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003289A0(void)
{
    DAT_004497E8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004497EC);
    DAT_004497EC = 0;
    DAT_004497F4 = 0;
    DAT_004497F6 = 0;
    DAT_004497FA = 0;
    return 0;
}
