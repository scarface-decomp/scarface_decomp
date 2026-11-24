// bin: xb
// va: 0x00325090
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325090 (0x00325090, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00433ECC;
extern "C" int DAT_00433ED0;
extern "C" unsigned short DAT_00433ED8;
extern "C" unsigned short DAT_00433EDA;
extern "C" unsigned short DAT_00433EDE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325090(void)
{
    DAT_00433ECC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00433ED0);
    DAT_00433ED0 = 0;
    DAT_00433ED8 = 0;
    DAT_00433EDA = 0;
    DAT_00433EDE = 0;
    return 0;
}
