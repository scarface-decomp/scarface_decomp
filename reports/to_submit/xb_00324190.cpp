// bin: xb
// va: 0x00324190
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324190 (0x00324190, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429764;
extern "C" int DAT_00429768;
extern "C" unsigned short DAT_00429770;
extern "C" unsigned short DAT_00429772;
extern "C" unsigned short DAT_00429776;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324190(void)
{
    DAT_00429764 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429768);
    DAT_00429768 = 0;
    DAT_00429770 = 0;
    DAT_00429772 = 0;
    DAT_00429776 = 0;
    return 0;
}
