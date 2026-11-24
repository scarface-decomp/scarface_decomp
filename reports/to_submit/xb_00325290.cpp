// bin: xb
// va: 0x00325290
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325290 (0x00325290, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043613C;
extern "C" int DAT_00436140;
extern "C" unsigned short DAT_00436148;
extern "C" unsigned short DAT_0043614A;
extern "C" unsigned short DAT_0043614E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325290(void)
{
    DAT_0043613C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436140);
    DAT_00436140 = 0;
    DAT_00436148 = 0;
    DAT_0043614A = 0;
    DAT_0043614E = 0;
    return 0;
}
