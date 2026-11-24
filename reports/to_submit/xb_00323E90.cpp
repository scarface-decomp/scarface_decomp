// bin: xb
// va: 0x00323E90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323E90 (0x00323E90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429554;
extern "C" int DAT_00429558;
extern "C" unsigned short DAT_00429560;
extern "C" unsigned short DAT_00429562;
extern "C" unsigned short DAT_00429566;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323E90(void)
{
    DAT_00429554 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429558);
    DAT_00429558 = 0;
    DAT_00429560 = 0;
    DAT_00429562 = 0;
    DAT_00429566 = 0;
    return 0;
}
