// bin: proto
// va: 0x0007D1E0
// tool: the portal's starter code (no AI)
// sub_0007D1E0 (0x0007D1E0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_0007D1E0
{
public:
    void sub_0007D1E0();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x6];
    bool m_Field16; // +0x16
    bool m_Field17; // +0x17
};

void Class_0007D1E0::sub_0007D1E0()
{
    int t1;

    if (m_Field17) {
        t1 = m_Field0C;
        if (m_Field0C) {
            ((Object*)t1)->vfunc_01();
            m_Field0C = 0;
        }
        m_Field16 = false;
        m_Field17 = false;
    }
}
