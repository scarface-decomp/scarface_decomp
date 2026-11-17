// bin: proto
// va: 0x0016EE30
// tool: the portal's starter code (no AI)
// sub_0016EE30 (0x0016EE30, 72 bytes)
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
    virtual void vfunc_31(int, int, int);
};

class Class_0016EE30
{
public:
    void sub_0016EE30();
    char m_pad00[0x18];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    char m_pad20[0x2C];
    unsigned char m_Field4C; // +0x4C
    unsigned char m_Field4D; // +0x4D
};

void Class_0016EE30::sub_0016EE30()
{
    int r_ebp, r_esi, t1;

    if (!(m_Field4C & 2)) {
        if (m_Field4D & 4) goto L_46;
        r_esi = m_Field1C;
        r_esi -= m_Field18;
        r_esi >>= 2;
        r_ebp = 0;
        if (r_esi > 0) {
            do {
                t1 = *(int*)(m_Field18 + (r_ebp * 4));
                if (*(int*)(m_Field18 + (r_ebp * 4))) {
                    ((Object*)t1)->vfunc_31(1, 1, 1);
                }
                r_ebp += 1;
            } while (r_ebp < r_esi);
        }
        m_Field4C = (unsigned char)(m_Field4C | 2);
    }
L_46:
    ;
}
