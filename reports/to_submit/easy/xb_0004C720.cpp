// bin: xb
// va: 0x0004C720
// tool: the portal's starter code (no AI)
// sub_0004C720 (0x0004C720, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_0004C720
{
public:
    void sub_0004C720(int a1, bool a2);
    char m_pad00[0x28];
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
};

void Class_0004C720::sub_0004C720(int a1, bool a2)
{
    int t2, t5;

    if (a2) {
        if (a1) {
            ((Object*)a1)->vfunc_00();
        }
        t2 = m_Field2C;
        if (m_Field2C) {
            ((Object*)t2)->vfunc_01();
        }
        m_Field2C = a1;
        return;
    }
    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    t5 = m_Field28;
    if (m_Field28) {
        ((Object*)t5)->vfunc_01();
    }
    m_Field28 = a1;
}
