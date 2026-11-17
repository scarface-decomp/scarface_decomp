// bin: pc
// va: 0x006E9A10
// tool: the portal's starter code (no AI)
// sub_006E9A10 (0x006E9A10, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    void sub_006E95A0(int, int);
};

class Class_006E9A10
{
public:
    void sub_006E9A10(int a1, int a2);
    char m_pad00[0x8];
    int m_Field08; // +0x08
};

void Class_006E9A10::sub_006E9A10(int a1, int a2)
{
    int t1;

    t1 = m_Field08;
    ((Object*)a2)->vfunc_00();
    ((Object*)t1)->sub_006E95A0(a1, a2);
}
