// bin: xb
// va: 0x003277C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003277C0 (0x003277C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00440550;
extern "C" int DAT_00440554;
extern "C" unsigned short DAT_0044055C;
extern "C" unsigned short DAT_0044055E;
extern "C" unsigned short DAT_00440562;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003277C0(void)
{
    DAT_00440550 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00440554);
    DAT_00440554 = 0;
    DAT_0044055C = 0;
    DAT_0044055E = 0;
    DAT_00440562 = 0;
    return 0;
}
