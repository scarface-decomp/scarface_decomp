// bin: xb
// va: 0x00326E40
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326E40 (0x00326E40, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043DAF8;
extern "C" int DAT_0043DAFC;
extern "C" unsigned short DAT_0043DB04;
extern "C" unsigned short DAT_0043DB06;
extern "C" unsigned short DAT_0043DB0A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326E40(void)
{
    DAT_0043DAF8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043DAFC);
    DAT_0043DAFC = 0;
    DAT_0043DB04 = 0;
    DAT_0043DB06 = 0;
    DAT_0043DB0A = 0;
    return 0;
}
