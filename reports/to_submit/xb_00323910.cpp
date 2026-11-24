// bin: xb
// va: 0x00323910
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323910 (0x00323910, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042918C;
extern "C" int DAT_00429190;
extern "C" unsigned short DAT_00429198;
extern "C" unsigned short DAT_0042919A;
extern "C" unsigned short DAT_0042919E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323910(void)
{
    DAT_0042918C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429190);
    DAT_00429190 = 0;
    DAT_00429198 = 0;
    DAT_0042919A = 0;
    DAT_0042919E = 0;
    return 0;
}
