// bin: xb
// va: 0x00048D80
// tool: the portal's starter code (no AI)
// sub_00048D80 (0x00048D80, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0005D870(int);
};

void __cdecl sub_00048D80(int a1, int a2)
{
    int t1;

    if (a1) {
        if (*(int*)(*(int*)(a1 + 4) + 84) != 16384) goto L_2B;
        if (!a2) goto L_2B;
        t1 = *(int*)(a2 + 4);
        if (*(int*)(*(int*)(a2 + 4) + 84) != 16) goto L_2B;
        ((Object*)*(int*)(a1 + 4))->sub_0005D870(t1);
    }
L_2B:
    ;
}
