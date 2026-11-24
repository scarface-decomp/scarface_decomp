// bin: xb
// va: 0x00328120
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328120 (0x00328120, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00445D74;
extern "C" int DAT_00445D78;
extern "C" unsigned short DAT_00445D80;
extern "C" unsigned short DAT_00445D82;
extern "C" unsigned short DAT_00445D86;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328120(void)
{
    DAT_00445D74 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00445D78);
    DAT_00445D78 = 0;
    DAT_00445D80 = 0;
    DAT_00445D82 = 0;
    DAT_00445D86 = 0;
    return 0;
}
