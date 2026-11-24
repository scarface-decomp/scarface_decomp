// bin: xb
// va: 0x00327480
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327480 (0x00327480, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043FAAC;
extern "C" int DAT_0043FAB0;
extern "C" unsigned short DAT_0043FAB8;
extern "C" unsigned short DAT_0043FABA;
extern "C" unsigned short DAT_0043FABE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327480(void)
{
    DAT_0043FAAC = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043FAB0);
    DAT_0043FAB0 = 0;
    DAT_0043FAB8 = 0;
    DAT_0043FABA = 0;
    DAT_0043FABE = 0;
    return 0;
}
