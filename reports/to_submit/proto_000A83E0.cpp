// bin: proto
// va: 0x000A83E0
// what: 
// tool: the portal's starter code (no AI)

// sub_000A83E0 (Proto 0x000A83E0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000A83E0
{
public:
    int sub_000A83E0();
    char m_pad00[0x40];
    bool m_Field40; // +0x40
    bool m_Field41; // +0x41
};

int Class_000A83E0::sub_000A83E0()
{
    if (!m_Field40) {
        if (m_Field41) goto L_11;
        return 0;
    }
L_11:
    return 1;
}
