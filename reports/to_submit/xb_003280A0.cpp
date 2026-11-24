// bin: xb
// va: 0x003280A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003280A0 (0x003280A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00445D1C;
extern "C" int DAT_00445D20;
extern "C" unsigned short DAT_00445D28;
extern "C" unsigned short DAT_00445D2A;
extern "C" unsigned short DAT_00445D2E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003280A0(void)
{
    DAT_00445D1C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00445D20);
    DAT_00445D20 = 0;
    DAT_00445D28 = 0;
    DAT_00445D2A = 0;
    DAT_00445D2E = 0;
    return 0;
}
