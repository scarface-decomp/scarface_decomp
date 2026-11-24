// bin: xb
// va: 0x00325F10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325F10 (0x00325F10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043800C;
extern "C" int DAT_00438010;
extern "C" unsigned short DAT_00438018;
extern "C" unsigned short DAT_0043801A;
extern "C" unsigned short DAT_0043801E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325F10(void)
{
    DAT_0043800C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00438010);
    DAT_00438010 = 0;
    DAT_00438018 = 0;
    DAT_0043801A = 0;
    DAT_0043801E = 0;
    return 0;
}
