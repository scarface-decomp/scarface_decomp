// bin: proto
// va: 0x000AF280
// tool: the portal's starter code (no AI)
// sub_000AF280 (0x000AF280, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00393980;

class Class_000AF280
{
public:
    int sub_000AF280();
    char m_pad00[0x1B4];
    float m_Field1B4; // +0x1B4
    char m_pad1B8[0x40];
    bool m_Field1F8; // +0x1F8
};

int Class_000AF280::sub_000AF280()
{
    if (!m_Field1F8) {
        if (DAT_00393980 > m_Field1B4) goto L_1E;
        return 0;
    }
L_1E:
    return 1;
}
