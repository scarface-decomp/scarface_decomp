// bin: xb
// va: 0x001973F0
// tool: the portal's starter code (no AI)
// GenericMenu::vfunc_00 (0x001973F0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
};

class GenericMenu
{
public:
    virtual void vfunc_00(int a1);
};

void GenericMenu::vfunc_00(int a1)
{
    int r_ebx, r_edi, r_esi, t1;

    r_edi = (int)this;
    r_esi = *(int*)(r_edi + 4);
    r_ebx = *(int*)(r_edi + 8);
    if (r_esi != r_ebx) {
        do {
            t1 = *(int*)r_esi;
            if (*(int*)r_esi) {
                ((Object*)t1)->vfunc_04(a1);
            }
            r_esi += 4;
        } while (r_esi != r_ebx);
    }
    if (*(bool*)(r_edi + 32)) {
        r_edi = *(int*)(r_edi + 24);
        if (!r_edi) goto L_3C;
        ((Object*)r_edi)->vfunc_00(a1);
    }
L_3C:
    ;
}
