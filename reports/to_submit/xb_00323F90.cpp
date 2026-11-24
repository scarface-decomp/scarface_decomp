// bin: xb
// va: 0x00323F90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323F90 (0x00323F90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429604;
extern "C" int DAT_00429608;
extern "C" unsigned short DAT_00429610;
extern "C" unsigned short DAT_00429612;
extern "C" unsigned short DAT_00429616;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323F90(void)
{
    DAT_00429604 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429608);
    DAT_00429608 = 0;
    DAT_00429610 = 0;
    DAT_00429612 = 0;
    DAT_00429616 = 0;
    return 0;
}
