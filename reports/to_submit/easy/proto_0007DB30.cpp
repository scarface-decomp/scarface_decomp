// bin: proto
// va: 0x0007DB30
// tool: the portal's starter code (no AI)
// sub_0007DB30 (0x0007DB30, 41 bytes)
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

class Class_0007DB30
{
public:
    void sub_0007DB30(int a1);
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

void Class_0007DB30::sub_0007DB30(int a1)
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
