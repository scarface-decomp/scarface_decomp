// bin: xb
// va: 0x001AA4C0
// tool: the portal's starter code (no AI)
// sub_001AA4C0 (0x001AA4C0, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001A98C0();
    void sub_001A9DC0(int);
};

extern "C" int DAT_004356E8;
extern "C" int DAT_004356EC;
extern "C" int __cdecl sub_001A9400(int);
extern "C" void __cdecl sub_001AA380(int);

void __cdecl sub_001AA4C0(int a1, int a2)
{
    int r_edi, t1;

    if (a2 == -1) goto L_54;
    r_edi = a1;
    t1 = sub_001A9400(a1);
    if (t1) {
        if (!*(bool*)(t1 + 16)) goto L_39;
        ((Object*)t1)->sub_001A98C0();
        ((Object*)t1)->sub_001A9DC0(a2);
        return;
    }
L_39:
    DAT_004356E8 = r_edi;
    if (DAT_004356EC == 1) {
        sub_001AA380(1);
    }
L_54:
    ;
}
