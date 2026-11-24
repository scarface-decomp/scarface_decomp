// bin: xb
// va: 0x00328020
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328020 (0x00328020, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00445CC4;
extern "C" int DAT_00445CC8;
extern "C" unsigned short DAT_00445CD0;
extern "C" unsigned short DAT_00445CD2;
extern "C" unsigned short DAT_00445CD6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328020(void)
{
    DAT_00445CC4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00445CC8);
    DAT_00445CC8 = 0;
    DAT_00445CD0 = 0;
    DAT_00445CD2 = 0;
    DAT_00445CD6 = 0;
    return 0;
}
