// bin: pc
// va: 0x006EB4E0
// tool: the portal's starter code (no AI)
// sub_006EB4E0 (0x006EB4E0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_006EB4E0
{
public:
    void sub_006EB4E0(int a1);
    char m_pad00[0x1C];
    int m_Field1C; // +0x1C
};

void Class_006EB4E0::sub_006EB4E0(int a1)
{
    int t2;

    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    t2 = m_Field1C;
    if (m_Field1C) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field1C = a1;
}
