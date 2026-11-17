// bin: pc
// va: 0x006ECD30
// tool: the portal's starter code (no AI)
// sub_006ECD30 (0x006ECD30, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);

int __cdecl sub_006ECD30(int a1, int a2)
{
    if (sub_006F33D0(a1, a2)) {
        if (!sub_006F33D0(a1, a2 + 4)) goto L_42;
        if (!sub_006F33D0(a1, a2 + 8)) goto L_42;
        return 1;
    }
L_42:
    return 0;
}
