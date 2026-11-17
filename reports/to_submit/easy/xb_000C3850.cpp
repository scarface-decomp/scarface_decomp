// bin: xb
// va: 0x000C3850
// tool: the portal's starter code (no AI)
// sub_000C3850 (0x000C3850, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class Class_000C3850
{
public:
    void sub_000C3850();
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
    int m_Field14; // +0x14
    bool m_Field18; // +0x18
};

void Class_000C3850::sub_000C3850()
{
    int t1, t3, t4;
    float t2;

    t1 = m_Field00;
    if (!m_Field00) goto L_4E;
    t2 = DAT_0039D65C;
    t3 = m_Field0C;
    if (m_Field0C) {
        if (t3 == m_Field08) goto L_46;
        m_Field08 = t3;
        t4 = *(int*)(t1 + 8);
        m_Field18 = false;
        m_Field0C = 0;
        m_Field14 = t4;
        m_Field10 = t2;
        return;
    }
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = t2;
    *(float*)((char*)this + 0x14) = t2;
    m_Field18 = false;
L_46:
    m_Field0C = 0;
    m_Field10 = t2;
L_4E:
    ;
}
