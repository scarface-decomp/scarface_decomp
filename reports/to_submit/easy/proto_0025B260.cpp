// bin: proto
// va: 0x0025B260
// tool: the portal's starter code (no AI)
// sub_0025B260 (0x0025B260, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_0025B260
{
public:
    void sub_0025B260(int a1);
    char m_pad00[0x34];
    int m_Field34; // +0x34
};

void Class_0025B260::sub_0025B260(int a1)
{
    int r_esi, t2;

    r_esi = *(int*)(a1 + 92);
    if (r_esi) {
        ((Object*)r_esi)->vfunc_00();
    }
    t2 = m_Field34;
    if (m_Field34) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field34 = r_esi;
}
