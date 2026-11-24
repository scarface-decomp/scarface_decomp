// bin: xb
// va: 0x00327FA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327FA0 (0x00327FA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00445C6C;
extern "C" int DAT_00445C70;
extern "C" unsigned short DAT_00445C78;
extern "C" unsigned short DAT_00445C7A;
extern "C" unsigned short DAT_00445C7E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327FA0(void)
{
    DAT_00445C6C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00445C70);
    DAT_00445C70 = 0;
    DAT_00445C78 = 0;
    DAT_00445C7A = 0;
    DAT_00445C7E = 0;
    return 0;
}
