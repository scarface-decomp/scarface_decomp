// bin: proto
// va: 0x000274A0
// tool: the portal's starter code (no AI)
// FEGroupObject::vfunc_11 (0x000274A0, 66 bytes)
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
    virtual int vfunc_11();
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
    virtual int vfunc_11();
};

int FEGroupObject::vfunc_11()
{
    int r_eax, r_ebx, r_ecx, r_edi, r_esi;

    r_ecx = (int)this;
    r_edi = r_ecx + 48;
    r_ecx = r_edi;
    r_eax = ((Object*)r_ecx)->sub_0008E380();
    r_ebx = (short)((unsigned short)r_eax);
    r_esi = 0;
    if (r_ebx <= 0) goto L_3E;
L_16:
    r_ecx = r_edi;
    r_eax = ((Object*)r_ecx)->sub_0008E380();
    r_eax = (short)((unsigned short)r_eax);
    if (r_esi >= 0) {
        if (r_esi >= r_eax) goto L_32;
        r_ecx = *(int*)r_edi;
        r_eax = (short)((unsigned short)r_esi);
        r_ecx = *(int*)(r_ecx + (r_eax * 4));
        goto L_34;
    }
L_32:
    r_ecx = 0;
L_34:
    r_eax = ((Object*)r_ecx)->vfunc_11();
    r_esi += 1;
    if (r_esi < r_ebx) goto L_16;
L_3E:
    return r_eax;
}
