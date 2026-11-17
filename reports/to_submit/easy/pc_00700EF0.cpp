// bin: pc
// va: 0x00700EF0
// tool: the portal's starter code (no AI)
// sub_00700EF0 (0x00700EF0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D580;

int __cdecl sub_00700EF0(void)
{
    int t1;

    t1 = DAT_0085D580;
    if (DAT_0085D580) {
        return t1 + -4;
    }
    return 0;
}
