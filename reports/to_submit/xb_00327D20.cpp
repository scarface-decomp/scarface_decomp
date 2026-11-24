// bin: xb
// va: 0x00327D20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327D20 (0x00327D20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00444084;
extern "C" int DAT_00444088;
extern "C" unsigned short DAT_00444090;
extern "C" unsigned short DAT_00444092;
extern "C" unsigned short DAT_00444096;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327D20(void)
{
    DAT_00444084 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00444088);
    DAT_00444088 = 0;
    DAT_00444090 = 0;
    DAT_00444092 = 0;
    DAT_00444096 = 0;
    return 0;
}
