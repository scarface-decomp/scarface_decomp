// bin: xb
// va: 0x001D99D0
// tool: the portal's starter code (no AI)
// sub_001D99D0 (0x001D99D0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001D99D0
{
public:
    int sub_001D99D0();
    char m_pad00[0x94];
    int m_Field94; // +0x94
    char m_pad98[0x4];
    bool m_Field9C; // +0x9C
};

int Class_001D99D0::sub_001D99D0()
{
    if (m_Field9C) {
        if (!(*(unsigned char*)(m_Field94 + 22) & 127)) goto L_1C;
        return 1;
    }
L_1C:
    return 0;
}
