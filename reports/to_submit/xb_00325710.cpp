// bin: xb
// va: 0x00325710
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325710 (0x00325710, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436AD8;
extern "C" int DAT_00436ADC;
extern "C" unsigned short DAT_00436AE4;
extern "C" unsigned short DAT_00436AE6;
extern "C" unsigned short DAT_00436AEA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325710(void)
{
    DAT_00436AD8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436ADC);
    DAT_00436ADC = 0;
    DAT_00436AE4 = 0;
    DAT_00436AE6 = 0;
    DAT_00436AEA = 0;
    return 0;
}
