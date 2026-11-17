// bin: proto
// va: 0x001F7FE0
// tool: the portal's starter code (no AI)
// sub_001F7FE0 (0x001F7FE0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_001F7FE0
{
public:
    void sub_001F7FE0(int a1, int a2, int a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void Class_001F7FE0::sub_001F7FE0(int a1, int a2, int a3)
{
    int t2;

    m_Field00 = a1;
    m_Field04 = a2;
    if (a3) {
        ((Object*)a3)->vfunc_00();
    }
    t2 = m_Field08;
    if (m_Field08) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field08 = a3;
    m_Field0C = 0;
    m_Field10 = 0;
}
