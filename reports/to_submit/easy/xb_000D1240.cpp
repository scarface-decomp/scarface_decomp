// bin: xb
// va: 0x000D1240
// tool: the portal's starter code (no AI)
// sub_000D1240 (0x000D1240, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000ABC70();
    int sub_000CE360();
    int sub_000CE970();
    bool sub_001646F0();
    int sub_00166CE0();
};

extern "C" bool __cdecl sub_000CFBE0(int, int);

bool __cdecl sub_000D1240(int a1)
{
    int r_edi, r_esi, t2;

    r_esi = a1;
    r_edi = *(int*)(((Object*)a1)->sub_000CE360() + 20);
    t2 = ((Object*)a1)->sub_000CE970();
    r_esi = 0;
    if (*(int*)(t2 + 20)) {
        r_esi = ((Object*)*(int*)(t2 + 20))->sub_000ABC70();
    }
    if (r_edi) {
        if (!r_esi) goto L_52;
        if (((Object*)r_edi)->sub_001646F0()) goto L_52;
        if (((Object*)r_edi)->sub_00166CE0() == r_esi) goto L_52;
        return sub_000CFBE0(r_edi, r_esi);
    }
L_52:
    return false;
}
