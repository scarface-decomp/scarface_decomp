// bin: proto
// va: 0x0017FC60
// tool: the portal's starter code (no AI)
// sub_0017FC60 (0x0017FC60, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0017F120(int);
    void sub_0017F290();
};

extern "C" int DAT_0040FAB0;
extern "C" int DAT_0040FAB4;
extern "C" int __cdecl sub_0017ECB0(int);
extern "C" void __cdecl sub_0017FB30(int);

void __cdecl sub_0017FC60(int a1, int a2)
{
    int r_edi, t1;

    if (a2 == -1) goto L_54;
    r_edi = a1;
    t1 = sub_0017ECB0(a1);
    if (t1) {
        if (!*(bool*)(t1 + 16)) goto L_39;
        ((Object*)t1)->sub_0017F290();
        ((Object*)t1)->sub_0017F120(a2);
        return;
    }
L_39:
    DAT_0040FAB0 = r_edi;
    if (DAT_0040FAB4 == 1) {
        sub_0017FB30(1);
    }
L_54:
    ;
}
