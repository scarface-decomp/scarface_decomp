// bin: xb
// va: 0x00325B10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325B10 (0x00325B10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004373E8;
extern "C" int DAT_004373EC;
extern "C" unsigned short DAT_004373F4;
extern "C" unsigned short DAT_004373F6;
extern "C" unsigned short DAT_004373FA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325B10(void)
{
    DAT_004373E8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004373EC);
    DAT_004373EC = 0;
    DAT_004373F4 = 0;
    DAT_004373F6 = 0;
    DAT_004373FA = 0;
    return 0;
}
