// bin: proto
// va: 0x0008E4E0
// tool: the portal's starter code (no AI)
// sub_0008E4E0 (0x0008E4E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0008E4E0
{
public:
    int sub_0008E4E0();
    int m_Field00; // +0x00
    char m_pad04[0x4];
    short m_Field08; // +0x08
    char m_pad0A[0x4];
    unsigned short m_Field0E; // +0x0E
};

int Class_0008E4E0::sub_0008E4E0()
{
    int t1;

    m_Field0E = 0;
    if (m_Field08 > 0) {
        t1 = m_Field00;
        if (!m_Field00) goto L_1A;
        m_Field0E = 1;
        return t1;
    }
L_1A:
    return 0;
}
