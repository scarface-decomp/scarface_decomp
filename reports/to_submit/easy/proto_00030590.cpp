// bin: proto
// va: 0x00030590
// tool: the portal's starter code (no AI)
// sub_00030590 (0x00030590, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00030590
{
public:
    bool sub_00030590();
    char m_pad00[0x4];
    int m_Field04; // +0x04
    char m_pad08[0x4];
    short m_Field0C; // +0x0C
    char m_pad0E[0xA];
    int m_Field18; // +0x18
    char m_pad1C[0x8];
    int m_Field24; // +0x24
    char m_pad28[0x8];
    int m_Field30; // +0x30
    char m_pad34[0x10];
    int m_Field44; // +0x44
};

bool Class_00030590::sub_00030590()
{
    int t1, t3, t4;
    short t2;

    t1 = m_Field18;
    if (m_Field18) {
        if (t1 == 3) goto L_4E;
        t2 = m_Field0C;
        if (m_Field0C < 2) goto L_4E;
        t3 = m_Field24;
        if (m_Field24 >= 255) goto L_4E;
        if (t3 < 0) goto L_4E;
        t4 = m_Field30;
        if (m_Field30 >= 255) goto L_4E;
        if (t4 < 0) goto L_4E;
        if (!m_Field44) goto L_4E;
        if (!*(int*)(m_Field04 + ((((short)((unsigned short)(t2 - 1))) + (((short)((unsigned short)(t2 - 1))) * 4)) * 4) + 12)) goto L_4E;
        return true;
    }
L_4E:
    return false;
}
