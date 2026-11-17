// bin: proto
// va: 0x000C0570
// tool: the portal's starter code (no AI)
// sub_000C0570 (0x000C0570, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00026D50();
    int sub_00056450();
    int sub_00084DA0();
};

extern "C" bool __cdecl sub_000C04C0(int, int);

bool __cdecl sub_000C0570(int a1)
{
    int t2, t4, t5;

    t2 = *(int*)(((Object*)a1)->sub_00056450() + 20);
    t4 = *(int*)(((Object*)a1)->sub_00026D50() + 20);
    if (t2) {
        if (!t4) goto L_3A;
        t5 = ((Object*)t4)->sub_00084DA0();
        if (!t5) goto L_3A;
        return sub_000C04C0(t2, t5);
    }
L_3A:
    return false;
}
