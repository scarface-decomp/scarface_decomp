// bin: proto
// va: 0x000914A0
// tool: the portal's starter code (no AI)
// WheeledLocomotion::vfunc_06 (0x000914A0, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    void sub_0009F2B0(int);
};

struct Field08
{
    void sub_000B48B0();
};

struct Object
{
    void sub_000B0990();
};

extern "C" float DAT_0037CE60;
extern "C" void __cdecl sub_001B7A10(void);

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
    Field04* m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    bool m_Field18; // +0x18
};

int WheeledLocomotion::vfunc_06()
{
    int r_eax, r_ebx, r_edi;
    float t5;

    sub_001B7A10();
    if (m_Field04) {
        m_Field04->sub_0009F2B0(0);
    }
    if (m_Field08) {
        m_Field08->sub_000B48B0();
    }
    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebx = 0;
        do {
            ((Object*)m_Field10 + r_ebx)->sub_000B0990();
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 592;
        } while (r_edi < r_eax);
    }
    t5 = DAT_0037CE60;
    m_Field18 = false;
    m_Field14 = t5;
    return r_eax;
}
