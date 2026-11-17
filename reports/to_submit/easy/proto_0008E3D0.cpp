// bin: proto
// va: 0x0008E3D0
// tool: the portal's starter code (no AI)
// sub_0008E3D0 (0x0008E3D0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0008E3D0
{
public:
    int sub_0008E3D0();
    int m_Field00; // +0x00
    char m_pad04[0x4];
    short m_Field08; // +0x08
    char m_pad0A[0x4];
    short m_Field0E; // +0x0E
};

int Class_0008E3D0::sub_0008E3D0()
{
    short t1;
    int t2;

    t1 = m_Field0E;
    if (m_Field0E >= 0) {
        if (t1 >= m_Field08) goto L_25;
        t2 = m_Field00;
        if (!m_Field00) goto L_25;
        m_Field0E = (unsigned short)(t1 + 1);
        return t2 + (((short)t1) * 4);
    }
L_25:
    return 0;
}
