// bin: proto
// va: 0x0007CD10
// tool: the portal's starter code (no AI)
// sub_0007CD10 (0x0007CD10, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0007CD10
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int, int);
    void sub_0007CD10(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    bool m_Field0C; // +0x0C
};

void Class_0007CD10::sub_0007CD10(int a1)
{
    int r_edi, t3;

    if (!m_Field0C) {
        vfunc_01(a1, m_Field04);
    }
    r_edi = 10;
    if (!m_Field0C) goto L_56;
L_27:
    r_edi -= 1;
    if (r_edi >= 0) {
        if (r_edi <= 0) goto L_56;
        vfunc_01(2, m_Field04);
        t3 = m_Field08;
        m_Field0C = false;
        m_Field04 = t3;
        vfunc_01(1, m_Field08);
        if (m_Field0C) goto L_27;
    }
L_56:
    ;
}
