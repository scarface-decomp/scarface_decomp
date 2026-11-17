// bin: pc
// va: 0x006EB4B0
// tool: the portal's starter code (no AI)
// sub_006EB4B0 (0x006EB4B0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_006EB4B0
{
public:
    void sub_006EB4B0(int a1);
    char m_pad00[0x18];
    int m_Field18; // +0x18
};

void Class_006EB4B0::sub_006EB4B0(int a1)
{
    int t2;

    if (a1) {
        ((Object*)a1)->vfunc_00();
    }
    t2 = m_Field18;
    if (m_Field18) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field18 = a1;
}
