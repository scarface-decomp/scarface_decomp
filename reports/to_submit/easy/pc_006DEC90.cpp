// bin: pc
// va: 0x006DEC90
// tool: the portal's starter code (no AI)
// sub_006DEC90 (0x006DEC90, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085AEB0[];
extern "C" int DAT_0085AEC8;
extern "C" void __cdecl sub_006DF050(int);

void __cdecl sub_006DEC90(void)
{
    sub_006DF050((int)DAT_0085AEB0);
    DAT_0085AEC8 = 0x55555555;
}
