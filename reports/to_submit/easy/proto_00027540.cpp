// bin: proto
// va: 0x00027540
// tool: the portal's starter code (no AI)
// FEGroupObject::vfunc_13 (0x00027540, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual int vfunc_13(int);
    int sub_0008E380();
};

class FEGroupObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual int vfunc_13(int a1);
};

int FEGroupObject::vfunc_13(int a1)
{
    int r_eax, r_ebp, r_ebx, r_ecx, r_edi, r_esi;

    r_ecx = (int)this;
    r_edi = r_ecx + 48;
    r_ecx = r_edi;
    r_eax = ((Object*)r_ecx)->sub_0008E380();
    r_ebx = (short)((unsigned short)r_eax);
    r_esi = 0;
    if (r_ebx <= 0) goto L_4A;
    r_ebp = a1;
L_20:
    r_ecx = r_edi;
    r_eax = ((Object*)r_ecx)->sub_0008E380();
    r_eax = (short)((unsigned short)r_eax);
    if (r_esi >= 0) {
        if (r_esi >= r_eax) goto L_3C;
        r_ecx = *(int*)r_edi;
        r_eax = (short)((unsigned short)r_esi);
        r_ecx = *(int*)(r_ecx + (r_eax * 4));
        goto L_3E;
    }
L_3C:
    r_ecx = 0;
L_3E:
    r_eax = ((Object*)r_ecx)->vfunc_13(r_ebp);
    r_esi += 1;
    if (r_esi < r_ebx) goto L_20;
L_4A:
    return r_eax;
}
