// bin: proto
// va: 0x00095560
// tool: the portal's starter code (no AI)
// BoatLocomotion::vfunc_05 (0x00095560, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_00094EE0();
    int sub_00094FC0();
};

struct Field0C
{
    void sub_000ADC00(int, int, int);
};

extern "C" void __cdecl sub_001B7A10(void);

class BoatLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    Field0C m_Field0C; // +0x0C
};

void BoatLocomotion::vfunc_05()
{
    int t3, t4;

    sub_001B7A10();
    if (!m_Field04) goto L_40;
    if (!m_Field08) goto L_40;
    t3 = m_Field08->sub_00094EE0();
    t4 = m_Field08->sub_00094FC0();
    if (t3) {
        if (!t4) goto L_3F;
        m_Field0C.sub_000ADC00(t3, t4, m_Field04 + 52);
    }
L_3F:
L_40:
    ;
}
