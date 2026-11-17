// bin: proto
// va: 0x00132950
// tool: the portal's starter code (no AI)
// sub_00132950 (0x00132950, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00132950
{
public:
    int sub_00132950();
    char m_pad00[0xBC];
    float m_FieldBC; // +0xBC
    char m_padC0[0x34];
    float m_FieldF4; // +0xF4
};

int Class_00132950::sub_00132950()
{
    if (m_FieldBC >= m_FieldF4) {
        return 1;
    }
    return 0;
}
