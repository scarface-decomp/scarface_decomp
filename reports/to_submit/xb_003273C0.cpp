// bin: xb
// va: 0x003273C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003273C0 (0x003273C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043FA28;
extern "C" int DAT_0043FA2C;
extern "C" unsigned short DAT_0043FA34;
extern "C" unsigned short DAT_0043FA36;
extern "C" unsigned short DAT_0043FA3A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003273C0(void)
{
    DAT_0043FA28 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043FA2C);
    DAT_0043FA2C = 0;
    DAT_0043FA34 = 0;
    DAT_0043FA36 = 0;
    DAT_0043FA3A = 0;
    return 0;
}
