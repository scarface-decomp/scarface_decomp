// bin: xb
// va: 0x00087ED0
// tool: the portal's starter code (no AI)
// sub_00087ED0 (0x00087ED0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

class Class_00087ED0
{
public:
    void sub_00087ED0();
    char m_pad00[0x10];
    int m_Field10; // +0x10
    bool m_Field14; // +0x14
};

void Class_00087ED0::sub_00087ED0()
{
    int r_edi, t1, t3;

    r_edi = 0;
    if (m_Field10 > 0) {
        do {
            t1 = *(int*)((int)this + (r_edi * 4));
            if (*(int*)((int)this + (r_edi * 4))) {
                ((Object*)t1)->vfunc_00(1);
            }
            t3 = m_Field10;
            r_edi += 1;
        } while (r_edi < t3);
    }
    m_Field10 = 0;
    m_Field14 = false;
}
