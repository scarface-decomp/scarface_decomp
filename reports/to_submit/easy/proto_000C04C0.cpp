// bin: proto
// va: 0x000C04C0
// tool: the portal's starter code (no AI)
// sub_000C04C0 (0x000C04C0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0009F970();
    bool sub_00148260();
    int sub_0014A290();
};

extern "C" bool __cdecl sub_000BF250(int, int);

bool __cdecl sub_000C04C0(int a1, int a2)
{
    int r_esi;

    r_esi = 0;
    if (a2) {
        r_esi = ((Object*)a2)->sub_0009F970();
    }
    if (a1) {
        if (!r_esi) goto L_42;
        if (((Object*)a1)->sub_00148260()) goto L_42;
        if (((Object*)a1)->sub_0014A290() == r_esi) goto L_42;
        return sub_000BF250(a1, r_esi);
    }
L_42:
    return false;
}
