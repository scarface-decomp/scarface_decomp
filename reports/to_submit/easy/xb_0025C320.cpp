// bin: xb
// va: 0x0025C320
// tool: the portal's starter code (no AI)
// sub_0025C320 (0x0025C320, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_0025FDE0(int);
};

void __stdcall sub_0025C320(int a1)
{
    int r_edi, r_esi, t2;

    r_edi = a1;
    if (!a1) goto L_34;
    r_esi = 0;
    if (*(int*)(r_edi + 16) <= 0) goto L_33;
L_15:
    if (r_esi < *(int*)(r_edi + 12)) {
        if (!*(int*)(*(int*)(r_edi + 20) + (r_esi * 4))) goto L_2B;
        ((Object*)*(int*)(*(int*)(r_edi + 20) + (r_esi * 4)))->sub_0025FDE0(1);
    }
L_2B:
    t2 = *(int*)(r_edi + 16);
    r_esi += 1;
    if (r_esi < t2) goto L_15;
L_33:
L_34:
    ;
}
