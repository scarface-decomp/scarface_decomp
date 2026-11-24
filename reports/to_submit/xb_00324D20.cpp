// bin: xb
// va: 0x00324D20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324D20 (0x00324D20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00430DC8;
extern "C" int DAT_00430DCC;
extern "C" unsigned short DAT_00430DD4;
extern "C" unsigned short DAT_00430DD6;
extern "C" unsigned short DAT_00430DDA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324D20(void)
{
    DAT_00430DC8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00430DCC);
    DAT_00430DCC = 0;
    DAT_00430DD4 = 0;
    DAT_00430DD6 = 0;
    DAT_00430DDA = 0;
    return 0;
}
