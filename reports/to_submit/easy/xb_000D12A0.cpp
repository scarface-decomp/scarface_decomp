// bin: xb
// va: 0x000D12A0
// tool: the portal's starter code (no AI)
// sub_000D12A0 (0x000D12A0, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000CE360();
    int sub_000CE970();
    int sub_001DE0E0();
};

extern "C" bool __cdecl sub_000D11F0(int, int);

bool __cdecl sub_000D12A0(int a1)
{
    int t2, t4, t5;

    t2 = *(int*)(((Object*)a1)->sub_000CE360() + 20);
    t4 = *(int*)(((Object*)a1)->sub_000CE970() + 20);
    if (t2) {
        if (!t4) goto L_3A;
        t5 = ((Object*)t4)->sub_001DE0E0();
        if (!t5) goto L_3A;
        return sub_000D11F0(t2, t5);
    }
L_3A:
    return false;
}
