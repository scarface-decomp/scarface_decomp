// bin: xb
// va: 0x000D11F0
// tool: the portal's starter code (no AI)
// sub_000D11F0 (0x000D11F0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000ABC70();
    bool sub_001646F0();
    int sub_00166CE0();
};

extern "C" bool __cdecl sub_000CFBE0(int, int);

bool __cdecl sub_000D11F0(int a1, int a2)
{
    int r_esi;

    r_esi = 0;
    if (a2) {
        r_esi = ((Object*)a2)->sub_000ABC70();
    }
    if (a1) {
        if (!r_esi) goto L_42;
        if (((Object*)a1)->sub_001646F0()) goto L_42;
        if (((Object*)a1)->sub_00166CE0() == r_esi) goto L_42;
        return sub_000CFBE0(a1, r_esi);
    }
L_42:
    return false;
}
