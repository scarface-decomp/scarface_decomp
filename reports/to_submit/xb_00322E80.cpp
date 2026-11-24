// bin: xb
// va: 0x00322E80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322E80 (0x00322E80, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0041F0F8;
extern "C" unsigned short DAT_0041F100;
extern "C" unsigned short DAT_0041F102;
extern "C" unsigned short DAT_0041F106;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322E80(void)
{
    sub_00027600(DAT_0041F0F8);
    DAT_0041F0F8 = 0;
    DAT_0041F100 = 0;
    DAT_0041F102 = 0;
    DAT_0041F106 = 0;
    return 0;
}
