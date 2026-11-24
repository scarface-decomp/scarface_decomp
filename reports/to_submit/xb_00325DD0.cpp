// bin: xb
// va: 0x00325DD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325DD0 (0x00325DD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00437D30;
extern "C" int DAT_00437D34;
extern "C" unsigned short DAT_00437D3C;
extern "C" unsigned short DAT_00437D3E;
extern "C" unsigned short DAT_00437D42;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325DD0(void)
{
    DAT_00437D30 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00437D34);
    DAT_00437D34 = 0;
    DAT_00437D3C = 0;
    DAT_00437D3E = 0;
    DAT_00437D42 = 0;
    return 0;
}
