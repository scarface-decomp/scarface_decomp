// bin: xb
// va: 0x00325AD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325AD0 (0x00325AD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00437288;
extern "C" int DAT_0043728C;
extern "C" unsigned short DAT_00437294;
extern "C" unsigned short DAT_00437296;
extern "C" unsigned short DAT_0043729A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325AD0(void)
{
    DAT_00437288 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043728C);
    DAT_0043728C = 0;
    DAT_00437294 = 0;
    DAT_00437296 = 0;
    DAT_0043729A = 0;
    return 0;
}
