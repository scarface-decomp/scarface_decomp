// bin: pc
// va: 0x006DF3E0
// what: Looks up an object and returns the number at +0x20 in it, or 0 when there is none.
// tool: Claude Opus 5.5 (transplanted from proto:0x0023F500, nearest by portal/tools/similar.py)
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