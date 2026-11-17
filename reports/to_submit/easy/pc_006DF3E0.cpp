// bin: pc
// va: 0x006DF3E0
// tool: the portal's starter code (no AI)
// sub_006DF3E0 (0x006DF3E0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006DF3A0(void);

int __cdecl sub_006DF3E0(void)
{
    int r_eax;

    r_eax = sub_006DF3A0();
    if (!r_eax) {
        return r_eax;
    }
    r_eax = *(int*)(r_eax + 32);
    return r_eax;
}
