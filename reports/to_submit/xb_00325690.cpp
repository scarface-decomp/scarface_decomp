// bin: xb
// va: 0x00325690
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325690 (0x00325690, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436890;
extern "C" int DAT_00436894;
extern "C" unsigned short DAT_0043689C;
extern "C" unsigned short DAT_0043689E;
extern "C" unsigned short DAT_004368A2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325690(void)
{
    DAT_00436890 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436894);
    DAT_00436894 = 0;
    DAT_0043689C = 0;
    DAT_0043689E = 0;
    DAT_004368A2 = 0;
    return 0;
}
