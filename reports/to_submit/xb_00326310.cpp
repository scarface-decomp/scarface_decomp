// bin: xb
// va: 0x00326310
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326310 (0x00326310, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00439E28;
extern "C" int DAT_00439E2C;
extern "C" unsigned short DAT_00439E34;
extern "C" unsigned short DAT_00439E36;
extern "C" unsigned short DAT_00439E3A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326310(void)
{
    DAT_00439E28 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00439E2C);
    DAT_00439E2C = 0;
    DAT_00439E34 = 0;
    DAT_00439E36 = 0;
    DAT_00439E3A = 0;
    return 0;
}
