// bin: xb
// va: 0x00326BC0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326BC0 (0x00326BC0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043D940;
extern "C" int DAT_0043D944;
extern "C" unsigned short DAT_0043D94C;
extern "C" unsigned short DAT_0043D94E;
extern "C" unsigned short DAT_0043D952;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326BC0(void)
{
    DAT_0043D940 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043D944);
    DAT_0043D944 = 0;
    DAT_0043D94C = 0;
    DAT_0043D94E = 0;
    DAT_0043D952 = 0;
    return 0;
}
