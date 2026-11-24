// bin: xb
// va: 0x00327A20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327A20 (0x00327A20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004421A8;
extern "C" int DAT_004421AC;
extern "C" unsigned short DAT_004421B4;
extern "C" unsigned short DAT_004421B6;
extern "C" unsigned short DAT_004421BA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327A20(void)
{
    DAT_004421A8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004421AC);
    DAT_004421AC = 0;
    DAT_004421B4 = 0;
    DAT_004421B6 = 0;
    DAT_004421BA = 0;
    return 0;
}
