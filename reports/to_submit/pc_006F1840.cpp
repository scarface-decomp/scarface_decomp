// bin: pc
// va: 0x006F1840
// what: 
// tool: the portal's starter code (no AI)

// sub_006F1840 (PC 0x006F1840, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F1840
{
public:
    int sub_006F1840();
    char m_pad00[0x78];
    unsigned char m_Field78; // +0x78
    unsigned char m_Field79; // +0x79
};

int Class_006F1840::sub_006F1840()
{
    if (!m_Field79) {
        return 0;
    }
    return (int)this + ((m_Field78 + (m_Field78 * 2)) * 4);
}
