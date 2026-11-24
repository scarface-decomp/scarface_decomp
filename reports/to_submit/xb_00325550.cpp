// bin: xb
// va: 0x00325550
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325550 (0x00325550, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436664;
extern "C" int DAT_00436668;
extern "C" unsigned short DAT_00436670;
extern "C" unsigned short DAT_00436672;
extern "C" unsigned short DAT_00436676;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325550(void)
{
    DAT_00436664 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436668);
    DAT_00436668 = 0;
    DAT_00436670 = 0;
    DAT_00436672 = 0;
    DAT_00436676 = 0;
    return 0;
}
