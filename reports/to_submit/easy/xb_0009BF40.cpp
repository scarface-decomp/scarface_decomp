// bin: xb
// va: 0x0009BF40
// tool: the portal's starter code (no AI)
// AirplaneLocomotion::vfunc_10 (0x0009BF40, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_0009B180();
};

struct Object
{
    void sub_000A76D0(float);
};

extern "C" float DAT_003A4980;

class AirplaneLocomotion
{
public:
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
    virtual bool vfunc_10();
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    char m_pad0C[0x44];
    bool m_Field50; // +0x50
};

bool AirplaneLocomotion::vfunc_10()
{
    int t1, t3, t4, t5;

    if (m_Field08) {
        t1 = m_Field04;
        if (!m_Field04) goto L_56;
        if (!*(bool*)(t1 + 1466)) goto L_56;
        if (!m_Field50) goto L_56;
        t3 = m_Field08->sub_0009B180();
        t4 = *(int*)(m_Field04 + 40);
        if (!t3) goto L_56;
        if (!t4) goto L_56;
        t5 = *(int*)(t3 + 16);
        if (!*(int*)(t3 + 16)) goto L_56;
        ((Object*)t5)->sub_000A76D0(*(float*)(t4 + 80) * DAT_003A4980);
    }
L_56:
    return m_Field50;
}
