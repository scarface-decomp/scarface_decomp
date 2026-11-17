// bin: proto
// va: 0x0007DAC0
// tool: the portal's starter code (no AI)
// sub_0007DAC0 (0x0007DAC0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual bool vfunc_03();
};

class Class_0007DAC0
{
public:
    void sub_0007DAC0();
    char m_pad00[0x10];
    int m_Field10; // +0x10
    bool m_Field14; // +0x14
};

void Class_0007DAC0::sub_0007DAC0()
{
    int r_edi, t4;

    r_edi = 0;
    m_Field14 = false;
    if (m_Field10 > 0) {
        do {
            if (((Object*)*(int*)((int)this + (r_edi * 4)))->vfunc_03()) {
                m_Field14 = true;
            }
            ((Object*)*(int*)((int)this + (r_edi * 4)))->vfunc_01();
            t4 = m_Field10;
            r_edi += 1;
        } while (r_edi < t4);
    }
}
