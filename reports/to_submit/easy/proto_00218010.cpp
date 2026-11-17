// bin: proto
// va: 0x00218010
// tool: the portal's starter code (no AI)
// sub_00218010 (0x00218010, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_00218010
{
public:
    void sub_00218010(int a1, int a2);
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

void Class_00218010::sub_00218010(int a1, int a2)
{
    int r_esi, t2;

    r_esi = m_Field14 + (a1 * 4);
    if (a2) {
        ((Object*)a2)->vfunc_00();
    }
    t2 = *(int*)r_esi;
    if (*(int*)r_esi) {
        ((Object*)t2)->vfunc_01();
    }
    *(int*)r_esi = a2;
}
