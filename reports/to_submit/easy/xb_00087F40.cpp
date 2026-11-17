// bin: xb
// va: 0x00087F40
// tool: the portal's starter code (no AI)
// sub_00087F40 (0x00087F40, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

class Class_00087F40
{
public:
    void sub_00087F40();
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

void Class_00087F40::sub_00087F40()
{
    int r_esi, t2;

    r_esi = 0;
    if (m_Field10 > 0) {
        do {
            ((Object*)*(int*)((int)this + (r_esi * 4)))->vfunc_02();
            t2 = m_Field10;
            r_esi += 1;
        } while (r_esi < t2);
    }
}
