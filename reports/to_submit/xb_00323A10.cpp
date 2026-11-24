// bin: xb
// va: 0x00323A10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323A10 (0x00323A10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042923C;
extern "C" int DAT_00429240;
extern "C" unsigned short DAT_00429248;
extern "C" unsigned short DAT_0042924A;
extern "C" unsigned short DAT_0042924E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323A10(void)
{
    DAT_0042923C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429240);
    DAT_00429240 = 0;
    DAT_00429248 = 0;
    DAT_0042924A = 0;
    DAT_0042924E = 0;
    return 0;
}
