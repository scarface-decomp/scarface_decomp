// bin: proto
// va: 0x000450B0
// tool: the portal's starter code (no AI)
// sub_000450B0 (0x000450B0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_000450B0
{
public:
    void sub_000450B0(int a1, bool a2);
    char m_pad00[0x38];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
};

void Class_000450B0::sub_000450B0(int a1, bool a2)
{
    int t2, t5;

    if (a2) {
        if (a1) {
            ((Object*)a1)->vfunc_00();
        }
        t2 = m_Field3C;
        if (m_Field3C) {
            ((Object*)t2)->vfunc_01();
        }
        m_Field3C = a1;
        return;
    }
    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    t5 = m_Field38;
    if (m_Field38) {
        ((Object*)t5)->vfunc_01();
    }
    m_Field38 = a1;
}
