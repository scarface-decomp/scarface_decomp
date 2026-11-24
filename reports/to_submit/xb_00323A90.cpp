// bin: xb
// va: 0x00323A90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323A90 (0x00323A90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429294;
extern "C" int DAT_00429298;
extern "C" unsigned short DAT_004292A0;
extern "C" unsigned short DAT_004292A2;
extern "C" unsigned short DAT_004292A6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323A90(void)
{
    DAT_00429294 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429298);
    DAT_00429298 = 0;
    DAT_004292A0 = 0;
    DAT_004292A2 = 0;
    DAT_004292A6 = 0;
    return 0;
}
