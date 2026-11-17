// bin: xb
// va: 0x0005E250
// tool: the portal's starter code (no AI)
// sub_0005E250 (0x0005E250, 56 bytes)
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
    virtual void vfunc_10(int);
};

class Class_0005E250
{
public:
    void sub_0005E250(int a1);
    char m_pad00[0x44];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
};

void Class_0005E250::sub_0005E250(int a1)
{
    int r_ebp, r_esi, t1, t2;

    t1 = (m_Field48 - m_Field44) >> 4;
    if (((m_Field48 - m_Field44) >> 4) > 0) {
        r_esi = 0;
        r_ebp = t1;
        do {
            t2 = *(int*)(r_esi + m_Field44);
            if (*(unsigned char*)(*(int*)(r_esi + m_Field44) + 80) & 1) {
                ((Object*)t2)->vfunc_10(a1);
            }
            r_esi += 16;
            r_ebp -= 1;
        } while (r_ebp);
    }
}
