// bin: xb
// va: 0x0009B300
// tool: the portal's starter code (no AI)
// AirplaneLocomotion::vfunc_03 (0x0009B300, 94 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_0009B100();
    int sub_0009B1B0();
    int sub_0009B240();
};

struct Field18
{
    void sub_000B2F80();
};

struct Field24
{
    void sub_000BB290(int, int, int);
};

extern "C" void __cdecl sub_002A9290(void);

class AirplaneLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    Field18 m_Field0C; // +0x0C
    char m_pad0D[0xB];
    Field18 m_Field18; // +0x18
    char m_pad19[0xB];
    Field24 m_Field24; // +0x24
};

void AirplaneLocomotion::vfunc_03()
{
    int t6, t7;

    sub_002A9290();
    if (m_Field08->sub_0009B1B0()) {
        m_Field18.sub_000B2F80();
    }
    m_Field0C.sub_000B2F80();
    if (!m_Field04) goto L_5C;
    if (!m_Field08) goto L_5C;
    t6 = m_Field08->sub_0009B100();
    t7 = m_Field08->sub_0009B240();
    if (t6) {
        if (!t7) goto L_5B;
        m_Field24.sub_000BB290(t6, t7, m_Field04 + 52);
    }
L_5B:
L_5C:
    ;
}
