// bin: pc
// va: 0x00700F20
// tool: the portal's starter code (no AI)
// sub_00700F20 (0x00700F20, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085D588[];
extern "C" void __cdecl sub_006DF080(int);

void __cdecl sub_00700F20(void)
{
    sub_006DF080((int)DAT_0085D588);
}
