// bin: xb
// va: 0x00323120
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323120 (0x00323120, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00424808;
extern "C" int DAT_0042480C;
extern "C" unsigned short DAT_00424814;
extern "C" unsigned short DAT_00424816;
extern "C" unsigned short DAT_0042481A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323120(void)
{
    DAT_00424808 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042480C);
    DAT_0042480C = 0;
    DAT_00424814 = 0;
    DAT_00424816 = 0;
    DAT_0042481A = 0;
    return 0;
}
