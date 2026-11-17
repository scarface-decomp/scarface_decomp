// bin: proto
// va: 0x00090810
// tool: the portal's starter code (no AI)
// AirplaneLocomotion::vfunc_12 (0x00090810, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    bool sub_0009FE50();
};

struct Field08
{
    int sub_0008F9D0();
};

struct Object
{
    void sub_0009B800(float);
};

extern "C" float DAT_00383ED4;

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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual bool vfunc_12();
    Field04* m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    char m_pad0C[0x44];
    bool m_Field50; // +0x50
};

bool AirplaneLocomotion::vfunc_12()
{
    int t4, t5, t6;

    if (m_Field08) {
        if (!m_Field04) goto L_58;
        if (!m_Field04->sub_0009FE50()) goto L_58;
        if (!m_Field50) goto L_58;
        t4 = m_Field08->sub_0008F9D0();
        t5 = *(int*)((int)m_Field04 + 40);
        if (!t4) goto L_58;
        if (!t5) goto L_58;
        t6 = *(int*)(t4 + 16);
        if (!*(int*)(t4 + 16)) goto L_58;
        ((Object*)t6)->sub_0009B800(*(float*)(t5 + 80) * DAT_00383ED4);
    }
L_58:
    return m_Field50;
}
