// bin: xb
// va: 0x00325BD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325BD0 (0x00325BD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00437890;
extern "C" int DAT_00437894;
extern "C" unsigned short DAT_0043789C;
extern "C" unsigned short DAT_0043789E;
extern "C" unsigned short DAT_004378A2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325BD0(void)
{
    DAT_00437890 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00437894);
    DAT_00437894 = 0;
    DAT_0043789C = 0;
    DAT_0043789E = 0;
    DAT_004378A2 = 0;
    return 0;
}
