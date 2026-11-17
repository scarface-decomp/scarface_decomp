// bin: xb
// va: 0x000783D0
// tool: the portal's starter code (no AI)
// sub_000783D0 (0x000783D0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00020FA0(int, int);
    void sub_000819A0(int);
    void sub_00081E10(int);
};

extern "C" int DAT_00480FA8;

void __cdecl sub_000783D0(int a1, bool a2)
{
    int local_4, t1, t2;

    t1 = *(int*)(DAT_00480FA8 + 292);
    t2 = DAT_00480FA8;
    if (*(int*)(DAT_00480FA8 + 292)) {
        *(unsigned char*)(t1 + 48) &= 223;
        if (a2) goto L_4F;
        ((Object*)*(int*)(t2 + 292))->sub_000819A0(500);
        ((Object*)*(int*)(DAT_00480FA8 + 292))->sub_00081E10(((Object*)(int)(&local_4))->sub_00020FA0(a1, 1));
    }
L_4F:
    ;
}
