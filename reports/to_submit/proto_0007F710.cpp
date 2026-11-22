// bin: proto
// va: 0x0007F710
// what: 
// tool: the portal's starter code (no AI)

// sub_0007F710 (Proto 0x0007F710, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0007F710
{
public:
    void sub_0007F710(bool a1);
    void sub_0007F490();
    char m_pad00[0x149];
    unsigned char m_Field149; // +0x149
};

void Class_0007F710::sub_0007F710(bool a1)
{
    unsigned char t1;

    t1 = m_Field149;
    if ((m_Field149 & 1) != (!a1)) {
        m_Field149 = (unsigned char)(((unsigned char)(((unsigned char)((!a1) ^ t1)) & 1)) ^ t1);
        sub_0007F490();
    }
}
