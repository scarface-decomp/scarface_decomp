// bin: xb
// va: 0x00322D30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322D30 (0x00322D30, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0041C44C;
extern "C" unsigned short DAT_0041C454;
extern "C" unsigned short DAT_0041C456;
extern "C" unsigned short DAT_0041C45A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322D30(void)
{
    sub_00027600(DAT_0041C44C);
    DAT_0041C44C = 0;
    DAT_0041C454 = 0;
    DAT_0041C456 = 0;
    DAT_0041C45A = 0;
    return 0;
}
