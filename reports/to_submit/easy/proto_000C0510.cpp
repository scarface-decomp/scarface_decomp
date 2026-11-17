// bin: proto
// va: 0x000C0510
// tool: the portal's starter code (no AI)
// sub_000C0510 (0x000C0510, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00026D50();
    int sub_00056450();
    int sub_0009F970();
    bool sub_00148260();
    int sub_0014A290();
};

extern "C" bool __cdecl sub_000BF250(int, int);

bool __cdecl sub_000C0510(int a1)
{
    int r_edi, r_esi, t2;

    r_esi = a1;
    r_edi = *(int*)(((Object*)a1)->sub_00056450() + 20);
    t2 = ((Object*)a1)->sub_00026D50();
    r_esi = 0;
    if (*(int*)(t2 + 20)) {
        r_esi = ((Object*)*(int*)(t2 + 20))->sub_0009F970();
    }
    if (r_edi) {
        if (!r_esi) goto L_52;
        if (((Object*)r_edi)->sub_00148260()) goto L_52;
        if (((Object*)r_edi)->sub_0014A290() == r_esi) goto L_52;
        return sub_000BF250(r_edi, r_esi);
    }
L_52:
    return false;
}
