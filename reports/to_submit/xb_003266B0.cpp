// bin: xb
// va: 0x003266B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003266B0 (0x003266B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043B1F8;
extern "C" int DAT_0043B1FC;
extern "C" unsigned short DAT_0043B204;
extern "C" unsigned short DAT_0043B206;
extern "C" unsigned short DAT_0043B20A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003266B0(void)
{
    DAT_0043B1F8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043B1FC);
    DAT_0043B1FC = 0;
    DAT_0043B204 = 0;
    DAT_0043B206 = 0;
    DAT_0043B20A = 0;
    return 0;
}
