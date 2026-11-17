// bin: proto
// va: 0x0026AFB0
// tool: the portal's starter code (no AI)
// sub_0026AFB0 (0x0026AFB0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
};

class Class_0026AFB0
{
public:
    void sub_0026AFB0();
    void sub_0026ADC0(int, int);
    char m_pad00[0x5];
    bool m_Field05; // +0x05
    char m_pad06[0x2];
    int m_Field08; // +0x08
    char m_pad0C[0x108];
    int m_Field114; // +0x114
};

void Class_0026AFB0::sub_0026AFB0()
{
    int r_esi, t1, t3;

    if (!m_Field05) goto L_40;
    t1 = m_Field114;
    m_Field05 = false;
    ((Object*)t1)->vfunc_03();
    r_esi = m_Field08;
    if (!r_esi) goto L_3F;
L_21:
    t3 = *(int*)(r_esi + 4);
    if (*(int*)(r_esi + 4) != 2) {
        if (t3 != 1) goto L_38;
    }
    sub_0026ADC0(r_esi, 0);
L_38:
    r_esi = *(int*)(r_esi + 24);
    if (r_esi) goto L_21;
L_3F:
L_40:
    ;
}
