// bin: xb
// va: 0x00033D20
// tool: the portal's starter code (no AI)
// sub_00033D20 (0x00033D20, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00033D20
{
public:
    bool sub_00033D20();
    char m_pad00[0x4];
    int m_Field04; // +0x04
    char m_pad08[0x4];
    short m_Field0C; // +0x0C
    char m_pad0E[0x6];
    bool m_Field14; // +0x14
    char m_pad15[0x7];
    int m_Field1C; // +0x1C
    char m_pad20[0x8];
    int m_Field28; // +0x28
    char m_pad2C[0x10];
    int m_Field3C; // +0x3C
};

bool Class_00033D20::sub_00033D20()
{
    bool t1;
    short t2;
    int t3, t4;

    t1 = m_Field14;
    if (m_Field14) {
        if (t1 == 3) goto L_4D;
        t2 = m_Field0C;
        if (m_Field0C < 2) goto L_4D;
        t3 = m_Field1C;
        if (m_Field1C >= 255) goto L_4D;
        if (t3 < 0) goto L_4D;
        t4 = m_Field28;
        if (m_Field28 >= 255) goto L_4D;
        if (t4 < 0) goto L_4D;
        if (!m_Field3C) goto L_4D;
        if (!*(int*)(m_Field04 + ((((short)((unsigned short)(t2 - 1))) + (((short)((unsigned short)(t2 - 1))) * 4)) * 4) + 12)) goto L_4D;
        return true;
    }
L_4D:
    return false;
}
