// bin: xb
// va: 0x00323CD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323CD0 (0x00323CD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429420;
extern "C" int DAT_00429424;
extern "C" unsigned short DAT_0042942C;
extern "C" unsigned short DAT_0042942E;
extern "C" unsigned short DAT_00429432;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323CD0(void)
{
    DAT_00429420 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429424);
    DAT_00429424 = 0;
    DAT_0042942C = 0;
    DAT_0042942E = 0;
    DAT_00429432 = 0;
    return 0;
}
