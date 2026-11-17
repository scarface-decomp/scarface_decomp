// bin: xb
// va: 0x001DE1D0
// tool: the portal's starter code (no AI)
// sub_001DE1D0 (0x001DE1D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    int sub_0002E680();
};

class Class_001DE1D0
{
public:
    void sub_001DE1D0();
    char m_pad00[0xC];
    Field0C* m_Field0C; // +0x0C
    char m_pad10[0x4];
    bool m_Field14; // +0x14
    bool m_Field15; // +0x15
    char m_pad16[0x1];
    unsigned char m_Field17; // +0x17
};

void Class_001DE1D0::sub_001DE1D0()
{
    int t2;

    if (!m_Field0C->sub_0002E680()) {
        if (m_Field15) goto L_22;
        t2 = m_Field17 & 254;
        m_Field14 = false;
        m_Field17 = (unsigned char)t2;
    }
L_22:
    ;
}
