// bin: xb
// va: 0x0009CBC0
// tool: the portal's starter code (no AI)
// WheeledLocomotion::vfunc_04 (0x0009CBC0, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    void sub_000AB410(int);
};

struct Field08
{
    void sub_000C22B0();
};

struct Object
{
    void sub_000BDF20();
};

extern "C" float DAT_0039D65C;
extern "C" void __cdecl sub_002A9290(void);

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    Field04* m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    bool m_Field18; // +0x18
};

int WheeledLocomotion::vfunc_04()
{
    int r_eax, r_ebx, r_edi;
    float t5;

    sub_002A9290();
    if (m_Field04) {
        m_Field04->sub_000AB410(0);
    }
    if (m_Field08) {
        m_Field08->sub_000C22B0();
    }
    r_eax = m_Field0C;
    r_edi = 0;
    if (r_eax > 0) {
        r_ebx = 0;
        do {
            ((Object*)m_Field10 + r_ebx)->sub_000BDF20();
            r_eax = m_Field0C;
            r_edi += 1;
            r_ebx += 548;
        } while (r_edi < r_eax);
    }
    t5 = DAT_0039D65C;
    m_Field18 = false;
    m_Field14 = t5;
    return r_eax;
}
