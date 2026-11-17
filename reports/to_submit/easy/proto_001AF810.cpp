// bin: proto
// va: 0x001AF810
// tool: the portal's starter code (no AI)
// sub_001AF810 (0x001AF810, 94 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_001AF810(int a1, int a2, int a3, int a4)
{
    int t3, t6, t9;

    if (((bool (__cdecl*)(int, int))a4)(*(int*)a2, *(int*)a1)) {
        t3 = *(int*)a2;
        *(int*)a2 = *(int*)a1;
        *(int*)a1 = t3;
    }
    if (((bool (__cdecl*)(int, int))a4)(*(int*)a3, *(int*)a2)) {
        t6 = *(int*)a3;
        *(int*)a3 = *(int*)a2;
        *(int*)a2 = t6;
    }
    if (((bool (__cdecl*)(int, int))a4)(*(int*)a2, *(int*)a1)) {
        t9 = *(int*)a2;
        *(int*)a2 = *(int*)a1;
        *(int*)a1 = t9;
    }
}
