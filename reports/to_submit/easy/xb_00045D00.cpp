// bin: xb
// va: 0x00045D00
// tool: the portal's starter code (no AI)
// sub_00045D00 (0x00045D00, 94 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0025CD40();
};

class Class_00045D00
{
public:
    void sub_00045D00(int a1);
};

void Class_00045D00::sub_00045D00(int a1)
{
    int r_ecx, r_edi, r_esi, t1, t3;

    r_ecx = (int)this;
    r_edi = (int)this;
    r_ecx = a1;
    t1 = *(int*)(r_edi + 108);
    if (*(int*)(r_edi + 108)) {
        if (*(int*)t1 != a1) goto L_25;
        r_ecx = *(int*)(t1 + 8);
        ((Object*)r_ecx)->sub_0025CD40();
        *(bool*)(*(int*)(r_edi + 108) + 12) = false;
        return;
    }
L_25:
    r_esi = *(int*)(r_edi + 40);
    r_edi = *(int*)(r_edi + 44);
    if ((unsigned int)r_esi >= (unsigned int)r_edi) goto L_59;
    do {
        t3 = *(int*)r_esi;
        if (*(bool*)(*(int*)r_esi + 12)) {
            if (r_ecx == *(int*)t3) goto L_49;
        }
        r_esi += 4;
    } while ((unsigned int)r_esi < (unsigned int)r_edi);
    return;
L_49:
    r_ecx = *(int*)r_esi;
    r_ecx = *(int*)(r_ecx + 8);
    ((Object*)r_ecx)->sub_0025CD40();
    *(bool*)(*(int*)r_esi + 12) = false;
L_59:
    ;
}
