// bin: proto
// va: 0x000B9390
// what: 
// tool: the portal's starter code (no AI)

// sub_000B9390 (Proto 0x000B9390, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000B9390
{
public:
    bool sub_000B9390();
    char m_pad00[0x30];
    int m_Field30; // +0x30
    char m_pad34[0x4];
    int m_Field38; // +0x38
};

bool Class_000B9390::sub_000B9390()
{
    if (!m_Field30) {
        if (m_Field38) goto L_11;
        return true;
    }
L_11:
    return false;
}
