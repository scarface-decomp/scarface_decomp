// bin: proto
// va: 0x00053A30
// tool: the portal's starter code (no AI)
// sub_00053A30 (0x00053A30, 64 bytes)
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

class Class_00053A30
{
public:
    void sub_00053A30(int a1);
    char m_pad00[0x44];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
};

void Class_00053A30::sub_00053A30(int a1)
{
    int r_ebp, r_ebx, r_esi, t1, t2;

    t1 = (m_Field48 - m_Field44) >> 4;
    if (((m_Field48 - m_Field44) >> 4) > 0) {
        r_ebp = a1;
        r_esi = 0;
        r_ebx = t1;
        do {
            t2 = *(int*)(r_esi + m_Field44);
            if (*(bool*)(*(int*)(r_esi + m_Field44) + 64)) {
                ((Object*)t2)->vfunc_10(r_ebp);
            }
            r_esi += 16;
            r_ebx -= 1;
        } while (r_ebx);
    }
}
