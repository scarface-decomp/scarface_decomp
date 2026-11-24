// bin: xb
// va: 0x003225C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003225C0 (0x003225C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00419FEC;
extern "C" int DAT_00419FF0;
extern "C" unsigned short DAT_00419FF8;
extern "C" unsigned short DAT_00419FFA;
extern "C" unsigned short DAT_00419FFE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003225C0(void)
{
    DAT_00419FEC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00419FF0);
    DAT_00419FF0 = 0;
    DAT_00419FF8 = 0;
    DAT_00419FFA = 0;
    DAT_00419FFE = 0;
    return 0;
}
