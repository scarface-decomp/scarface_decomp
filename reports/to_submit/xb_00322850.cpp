// bin: xb
// va: 0x00322850
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322850 (0x00322850, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041AC98;
extern "C" int DAT_0041AC9C;
extern "C" unsigned short DAT_0041ACA4;
extern "C" unsigned short DAT_0041ACA6;
extern "C" unsigned short DAT_0041ACAA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322850(void)
{
    DAT_0041AC98 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041AC9C);
    DAT_0041AC9C = 0;
    DAT_0041ACA4 = 0;
    DAT_0041ACA6 = 0;
    DAT_0041ACAA = 0;
    return 0;
}
