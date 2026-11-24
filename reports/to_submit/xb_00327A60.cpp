// bin: xb
// va: 0x00327A60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327A60 (0x00327A60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004421D4;
extern "C" int DAT_004421D8;
extern "C" unsigned short DAT_004421E0;
extern "C" unsigned short DAT_004421E2;
extern "C" unsigned short DAT_004421E6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327A60(void)
{
    DAT_004421D4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004421D8);
    DAT_004421D8 = 0;
    DAT_004421E0 = 0;
    DAT_004421E2 = 0;
    DAT_004421E6 = 0;
    return 0;
}
