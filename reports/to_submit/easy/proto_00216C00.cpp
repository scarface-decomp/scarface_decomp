// bin: proto
// va: 0x00216C00
// tool: the portal's starter code (no AI)
// sub_00216C00 (0x00216C00, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual bool vfunc_11();
    virtual bool vfunc_12();
};

class Class_00216C00
{
public:
    void sub_00216C00();
    char m_pad00[0x38];
    unsigned char m_Field38; // +0x38
    char m_pad39[0xB];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
};

void Class_00216C00::sub_00216C00()
{
    int r_ebp, r_edi, t1;

    t1 = (m_Field48 - m_Field44) >> 4;
    if (((m_Field48 - m_Field44) >> 4) > 0) {
        r_edi = 0;
        r_ebp = t1;
        do {
            if (((Object*)*(int*)(r_edi + m_Field44))->vfunc_11()) {
                m_Field38 |= 1;
            }
            if (((Object*)*(int*)(r_edi + m_Field44))->vfunc_12()) {
                m_Field38 |= 2;
            }
            r_edi += 16;
            r_ebp -= 1;
        } while (r_ebp);
    }
}
