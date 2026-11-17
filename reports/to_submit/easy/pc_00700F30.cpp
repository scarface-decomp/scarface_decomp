// bin: pc
// va: 0x00700F30
// tool: the portal's starter code (no AI)
// sub_00700F30 (0x00700F30, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085D588[];
extern "C" void __cdecl sub_006DF070(int);

void __cdecl sub_00700F30(void)
{
    sub_006DF070((int)DAT_0085D588);
}
