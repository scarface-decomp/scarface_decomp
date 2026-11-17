// bin: proto
// va: 0x001A1F40
// tool: the portal's starter code (no AI)
// sub_001A1F40 (0x001A1F40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001A1F40
{
public:
    int sub_001A1F40();
    char m_pad00[0x98];
    int m_Field98; // +0x98
    char m_pad9C[0x4];
    bool m_FieldA0; // +0xA0
};

int Class_001A1F40::sub_001A1F40()
{
    if (m_FieldA0) {
        if (!*(bool*)(m_Field98 + 20)) goto L_1D;
        return 1;
    }
L_1D:
    return 0;
}
