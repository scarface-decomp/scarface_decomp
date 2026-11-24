// bin: xb
// va: 0x00323DD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323DD0 (0x00323DD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004294D0;
extern "C" int DAT_004294D4;
extern "C" unsigned short DAT_004294DC;
extern "C" unsigned short DAT_004294DE;
extern "C" unsigned short DAT_004294E2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323DD0(void)
{
    DAT_004294D0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004294D4);
    DAT_004294D4 = 0;
    DAT_004294DC = 0;
    DAT_004294DE = 0;
    DAT_004294E2 = 0;
    return 0;
}
