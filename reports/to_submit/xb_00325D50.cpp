// bin: xb
// va: 0x00325D50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325D50 (0x00325D50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00437C44;
extern "C" int DAT_00437C48;
extern "C" unsigned short DAT_00437C50;
extern "C" unsigned short DAT_00437C52;
extern "C" unsigned short DAT_00437C56;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325D50(void)
{
    DAT_00437C44 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00437C48);
    DAT_00437C48 = 0;
    DAT_00437C50 = 0;
    DAT_00437C52 = 0;
    DAT_00437C56 = 0;
    return 0;
}
