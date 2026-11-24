// bin: xb
// va: 0x00327B60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327B60 (0x00327B60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00442554;
extern "C" int DAT_00442558;
extern "C" unsigned short DAT_00442560;
extern "C" unsigned short DAT_00442562;
extern "C" unsigned short DAT_00442566;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327B60(void)
{
    DAT_00442554 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00442558);
    DAT_00442558 = 0;
    DAT_00442560 = 0;
    DAT_00442562 = 0;
    DAT_00442566 = 0;
    return 0;
}
