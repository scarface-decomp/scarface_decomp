// bin: proto
// va: 0x0007D400
// what: 
// tool: the portal's starter code (no AI)

// sub_0007D400 (Proto 0x0007D400, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0007D400
{
public:
    void sub_0007D400();
    bool m_Field00; // +0x00
    char m_pad01[0xB];
    int m_Field0C; // +0x0C
    char m_pad10[0x8];
    int m_Field18; // +0x18
    char m_pad1C[0xE];
    unsigned short m_Field2A; // +0x2A
};

void Class_0007D400::sub_0007D400()
{
    int t1;

    if (!m_Field00) goto L_21;
    t1 = m_Field0C;
    if (m_Field0C) {
        if (!*(unsigned char*)t1) goto L_19;
        m_Field18 = 0;
        m_Field0C = 0;
    }
L_19:
    m_Field2A = 65535;
    m_Field00 = false;
L_21:
    ;
}
