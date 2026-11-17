// bin: proto
// va: 0x00091440
// tool: the portal's starter code (no AI)
// sub_00091440 (0x00091440, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00091440
{
public:
    int sub_00091440();
    char m_pad00[0xE4];
    bool m_FieldE4; // +0xE4
    bool m_FieldE5; // +0xE5
};

int Class_00091440::sub_00091440()
{
    if (!m_FieldE4) {
        if (m_FieldE5) goto L_17;
        return 0;
    }
L_17:
    return 1;
}
