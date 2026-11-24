// bin: xb
// va: 0x003253D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003253D0 (0x003253D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043636C;
extern "C" int DAT_00436370;
extern "C" unsigned short DAT_00436378;
extern "C" unsigned short DAT_0043637A;
extern "C" unsigned short DAT_0043637E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003253D0(void)
{
    DAT_0043636C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436370);
    DAT_00436370 = 0;
    DAT_00436378 = 0;
    DAT_0043637A = 0;
    DAT_0043637E = 0;
    return 0;
}
