// bin: xb
// va: 0x00326F40
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326F40 (0x00326F40, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043DBA8;
extern "C" int DAT_0043DBAC;
extern "C" unsigned short DAT_0043DBB4;
extern "C" unsigned short DAT_0043DBB6;
extern "C" unsigned short DAT_0043DBBA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326F40(void)
{
    DAT_0043DBA8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043DBAC);
    DAT_0043DBAC = 0;
    DAT_0043DBB4 = 0;
    DAT_0043DBB6 = 0;
    DAT_0043DBBA = 0;
    return 0;
}
