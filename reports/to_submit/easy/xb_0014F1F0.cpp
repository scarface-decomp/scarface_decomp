// bin: xb
// va: 0x0014F1F0
// tool: the portal's starter code (no AI)
// sub_0014F1F0 (0x0014F1F0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0014F1F0
{
public:
    int sub_0014F1F0();
    char m_pad00[0xBC];
    float m_FieldBC; // +0xBC
    char m_padC0[0x34];
    float m_FieldF4; // +0xF4
};

int Class_0014F1F0::sub_0014F1F0()
{
    if (m_FieldBC >= m_FieldF4) {
        return 1;
    }
    return 0;
}
