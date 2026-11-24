// bin: xb
// va: 0x00325E10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325E10 (0x00325E10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00437DC0;
extern "C" int DAT_00437DC4;
extern "C" unsigned short DAT_00437DCC;
extern "C" unsigned short DAT_00437DCE;
extern "C" unsigned short DAT_00437DD2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325E10(void)
{
    DAT_00437DC0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00437DC4);
    DAT_00437DC4 = 0;
    DAT_00437DCC = 0;
    DAT_00437DCE = 0;
    DAT_00437DD2 = 0;
    return 0;
}
