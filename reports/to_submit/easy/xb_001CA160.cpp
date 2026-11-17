// bin: xb
// va: 0x001CA160
// tool: the portal's starter code (no AI)
// PauseMenu::vfunc_32 (0x001CA160, 79 bytes)
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32(int);
};

class PauseMenu
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32(int a1);
    void sub_00193200(int);
    char m_pad04[0x24];
    int m_Field28; // +0x28
    char m_pad2C[0x34];
    unsigned char m_Field60; // +0x60
    char m_pad61[0x7];
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
};

void PauseMenu::vfunc_32(int a1)
{
    int r_ebp, r_ebx, r_esi, t2;

    if (!(m_Field60 & 1)) {
        if (m_Field28 == -1) goto L_4B;
    }
    r_ebp = a1;
    sub_00193200(a1);
    r_esi = m_Field6C;
    r_esi -= m_Field68;
    r_esi >>= 2;
    r_ebx = 0;
    if (r_esi > 0) {
        do {
            t2 = *(int*)(m_Field68 + (r_ebx * 4));
            if (*(int*)(m_Field68 + (r_ebx * 4))) {
                ((Object*)t2)->vfunc_32(r_ebp);
            }
            r_ebx += 1;
        } while (r_ebx < r_esi);
    }
L_4B:
    ;
}
