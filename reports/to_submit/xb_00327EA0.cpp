// bin: xb
// va: 0x00327EA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327EA0 (0x00327EA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00444694;
extern "C" int DAT_00444698;
extern "C" unsigned short DAT_004446A0;
extern "C" unsigned short DAT_004446A2;
extern "C" unsigned short DAT_004446A6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327EA0(void)
{
    DAT_00444694 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00444698);
    DAT_00444698 = 0;
    DAT_004446A0 = 0;
    DAT_004446A2 = 0;
    DAT_004446A6 = 0;
    return 0;
}
