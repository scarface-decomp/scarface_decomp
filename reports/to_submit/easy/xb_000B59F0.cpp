// bin: xb
// va: 0x000B59F0
// tool: the portal's starter code (no AI)
// sub_000B59F0 (0x000B59F0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000B59F0
{
public:
    int sub_000B59F0();
    char m_pad00[0x40];
    bool m_Field40; // +0x40
    bool m_Field41; // +0x41
};

int Class_000B59F0::sub_000B59F0()
{
    if (!m_Field40) {
        if (m_Field41) goto L_11;
        return 0;
    }
L_11:
    return 1;
}
