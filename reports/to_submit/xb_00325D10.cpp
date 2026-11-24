// bin: xb
// va: 0x00325D10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325D10 (0x00325D10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00437BCC;
extern "C" int DAT_00437BD0;
extern "C" unsigned short DAT_00437BD8;
extern "C" unsigned short DAT_00437BDA;
extern "C" unsigned short DAT_00437BDE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325D10(void)
{
    DAT_00437BCC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00437BD0);
    DAT_00437BD0 = 0;
    DAT_00437BD8 = 0;
    DAT_00437BDA = 0;
    DAT_00437BDE = 0;
    return 0;
}
