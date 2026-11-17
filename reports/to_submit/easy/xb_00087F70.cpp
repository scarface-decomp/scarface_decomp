// bin: xb
// va: 0x00087F70
// tool: the portal's starter code (no AI)
// sub_00087F70 (0x00087F70, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
};

class Class_00087F70
{
public:
    void sub_00087F70(int a1);
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

void Class_00087F70::sub_00087F70(int a1)
{
    int r_ebx, r_esi, t2;

    r_esi = 0;
    if (m_Field10 > 0) {
        r_ebx = a1;
        do {
            ((Object*)*(int*)((int)this + (r_esi * 4)))->vfunc_04(r_ebx);
            t2 = m_Field10;
            r_esi += 1;
        } while (r_esi < t2);
    }
}
