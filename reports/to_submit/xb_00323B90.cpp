// bin: xb
// va: 0x00323B90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323B90 (0x00323B90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429344;
extern "C" int DAT_00429348;
extern "C" unsigned short DAT_00429350;
extern "C" unsigned short DAT_00429352;
extern "C" unsigned short DAT_00429356;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323B90(void)
{
    DAT_00429344 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429348);
    DAT_00429348 = 0;
    DAT_00429350 = 0;
    DAT_00429352 = 0;
    DAT_00429356 = 0;
    return 0;
}
