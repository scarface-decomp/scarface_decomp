// bin: xb
// va: 0x00327FE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327FE0 (0x00327FE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00445C98;
extern "C" int DAT_00445C9C;
extern "C" unsigned short DAT_00445CA4;
extern "C" unsigned short DAT_00445CA6;
extern "C" unsigned short DAT_00445CAA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327FE0(void)
{
    DAT_00445C98 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00445C9C);
    DAT_00445C9C = 0;
    DAT_00445CA4 = 0;
    DAT_00445CA6 = 0;
    DAT_00445CAA = 0;
    return 0;
}
