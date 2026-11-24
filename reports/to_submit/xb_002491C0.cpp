// bin: xb
// va: 0x002491C0
// what: 
// tool: the portal's starter code (no AI)

// sub_002491C0 (0x002491C0, 127 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int __cdecl sub_00027590(int);
extern "C" void __cdecl sub_00027600(int);
extern "C" int __cdecl sub_0024B8F0(int);
extern "C" void __cdecl sub_0024B910(int, int, int);

class Class_002491C0
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    void sub_002491C0(int a1);
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
    char m_pad50[0x3];
    unsigned char m_Field53; // +0x53
};

void Class_002491C0::sub_002491C0(int a1)
{
    int r_eax, r_ebx, r_edi, t6;

    r_ebx = a1;
    r_eax = sub_0024B8F0(a1);
    r_edi = r_eax;
    r_eax = m_Field53;
    if (((unsigned char)r_eax) & 2) {
        r_eax = m_Field4C;
        if (!r_eax) goto L_49;
        r_eax = sub_0024B8F0(r_eax);
        if (r_eax > r_edi) goto L_59;
        r_eax = m_Field4C;
        sub_00027600(r_eax);
        r_eax = sub_00027590(r_edi + r_edi + 2);
        goto L_56;
    }
L_49:
    r_eax = sub_00027590(r_edi + r_edi + 2);
L_56:
    m_Field4C = r_eax;
L_59:
    r_eax = m_Field4C;
    t6 = m_Field53 | 2;
    r_edi += 1;
    m_Field53 = (unsigned char)t6;
    sub_0024B910(r_ebx, r_eax, r_edi);
    vfunc_14();
}
