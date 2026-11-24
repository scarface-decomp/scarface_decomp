// bin: xb
// va: 0x00326410
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326410 (0x00326410, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043A1F8;
extern "C" int DAT_0043A1FC;
extern "C" unsigned short DAT_0043A204;
extern "C" unsigned short DAT_0043A206;
extern "C" unsigned short DAT_0043A20A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326410(void)
{
    DAT_0043A1F8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043A1FC);
    DAT_0043A1FC = 0;
    DAT_0043A204 = 0;
    DAT_0043A206 = 0;
    DAT_0043A20A = 0;
    return 0;
}
