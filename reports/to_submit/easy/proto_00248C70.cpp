// bin: proto
// va: 0x00248C70
// tool: the portal's starter code (no AI)
// sub_00248C70 (0x00248C70, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_00248C70
{
public:
    void sub_00248C70(int a1);
    char m_pad00[0x38];
    int m_Field38; // +0x38
};

void Class_00248C70::sub_00248C70(int a1)
{
    int r_esi, t2;

    r_esi = *(int*)(a1 + 104);
    if (r_esi) {
        ((Object*)r_esi)->vfunc_00();
    }
    t2 = m_Field38;
    if (m_Field38) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field38 = r_esi;
}
