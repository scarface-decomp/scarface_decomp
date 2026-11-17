// bin: proto
// va: 0x0016EED0
// tool: the portal's starter code (no AI)
// HUDManager2::vfunc_02 (0x0016EED0, 96 bytes)
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30(int);
};

class HUDManager2
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    char m_pad10[0x8];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

void HUDManager2::vfunc_02(int a1, int a2, int a3)
{
    int r_ebx, r_edi, t1, t3;

    r_edi = m_Field0C;
    r_edi -= m_Field08;
    r_edi >>= 2;
    r_ebx = 0;
    if (r_edi > 0) {
        do {
            t1 = *(int*)(m_Field08 + (r_ebx * 4));
            if (*(int*)(m_Field08 + (r_ebx * 4))) {
                ((Object*)t1)->vfunc_30(a1);
            }
            r_ebx += 1;
        } while (r_ebx < r_edi);
    }
    r_edi = m_Field1C;
    r_edi -= m_Field18;
    r_edi >>= 2;
    r_ebx = 0;
    if (r_edi > 0) {
        do {
            t3 = *(int*)(m_Field18 + (r_ebx * 4));
            if (*(int*)(m_Field18 + (r_ebx * 4))) {
                ((Object*)t3)->vfunc_30(a1);
            }
            r_ebx += 1;
        } while (r_ebx < r_edi);
    }
}
