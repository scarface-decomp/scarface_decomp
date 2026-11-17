// bin: proto
// va: 0x00086990
// tool: the portal's starter code (no AI)
// sub_00086990 (0x00086990, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00086990
{
public:
    void sub_00086990();
    int m_Field00; // +0x00
    char m_pad04[0x20];
    unsigned char m_Field24; // +0x24
};

void Class_00086990::sub_00086990()
{
    unsigned char t1;

    if (m_Field00) {
        t1 = m_Field24;
        if (!(m_Field24 & 2)) goto L_17;
        m_Field00 = 0;
        m_Field24 = (unsigned char)(t1 & 253);
    }
L_17:
    ;
}
