// bin: proto
// va: 0x0020D080
// tool: the portal's starter code (no AI)
// sub_0020D080 (0x0020D080, 62 bytes)
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
    virtual void vfunc_07(int);
};

class Class_0020D080
{
public:
    void sub_0020D080(int a1);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x80];
    char m_Field90; // +0x90
};

void Class_0020D080::sub_0020D080(int a1)
{
    int r_ebp, r_edi, r_esi;
    char t2;

    r_esi = 0;
    if (m_Field90 > 0) {
        r_ebp = a1;
        r_edi = (int)(&m_Field0C);
        do {
            ((Object*)*(int*)r_edi)->vfunc_07(r_ebp);
            t2 = m_Field90;
            r_esi += 1;
            r_edi += 4;
        } while (r_esi < t2);
    }
}
