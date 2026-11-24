// bin: xb
// va: 0x00326190
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326190 (0x00326190, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00439D20;
extern "C" int DAT_00439D24;
extern "C" unsigned short DAT_00439D2C;
extern "C" unsigned short DAT_00439D2E;
extern "C" unsigned short DAT_00439D32;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326190(void)
{
    DAT_00439D20 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00439D24);
    DAT_00439D24 = 0;
    DAT_00439D2C = 0;
    DAT_00439D2E = 0;
    DAT_00439D32 = 0;
    return 0;
}
