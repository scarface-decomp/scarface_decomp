// bin: xb
// va: 0x00325250
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325250 (0x00325250, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436094;
extern "C" int DAT_00436098;
extern "C" unsigned short DAT_004360A0;
extern "C" unsigned short DAT_004360A2;
extern "C" unsigned short DAT_004360A6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325250(void)
{
    DAT_00436094 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436098);
    DAT_00436098 = 0;
    DAT_004360A0 = 0;
    DAT_004360A2 = 0;
    DAT_004360A6 = 0;
    return 0;
}
