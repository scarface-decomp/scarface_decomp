// bin: xb
// va: 0x00324DA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324DA0 (0x00324DA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00430E20;
extern "C" int DAT_00430E24;
extern "C" unsigned short DAT_00430E2C;
extern "C" unsigned short DAT_00430E2E;
extern "C" unsigned short DAT_00430E32;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324DA0(void)
{
    DAT_00430E20 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00430E24);
    DAT_00430E24 = 0;
    DAT_00430E2C = 0;
    DAT_00430E2E = 0;
    DAT_00430E32 = 0;
    return 0;
}
