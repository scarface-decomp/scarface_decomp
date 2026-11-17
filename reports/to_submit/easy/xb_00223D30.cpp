// bin: xb
// va: 0x00223D30
// tool: the portal's starter code (no AI)
// sub_00223D30 (0x00223D30, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00223D30
{
public:
    int sub_00223D30();
    char m_pad00[0x88];
    unsigned short m_Field88; // +0x88
    unsigned char m_Field8A; // +0x8A
};

int Class_00223D30::sub_00223D30()
{
    if (m_Field8A & 1) {
        return m_Field88;
    }
    return 65535;
}
