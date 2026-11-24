// bin: xb
// va: 0x00328820
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328820 (0x00328820, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447C1C;
extern "C" int DAT_00447C20;
extern "C" unsigned short DAT_00447C28;
extern "C" unsigned short DAT_00447C2A;
extern "C" unsigned short DAT_00447C2E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328820(void)
{
    DAT_00447C1C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447C20);
    DAT_00447C20 = 0;
    DAT_00447C28 = 0;
    DAT_00447C2A = 0;
    DAT_00447C2E = 0;
    return 0;
}
