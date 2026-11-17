// bin: proto
// va: 0x000B1FA0
// tool: the portal's starter code (no AI)
// sub_000B1FA0 (0x000B1FA0, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_000B4990();
};

extern "C" float DAT_00393980;

class Class_000B1FA0
{
public:
    void sub_000B1FA0(float a1);
    void sub_000B0EE0(float, int);
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    char m_pad0C[0x1A8];
    float m_Field1B4; // +0x1B4
    char m_pad1B8[0x40];
    bool m_Field1F8; // +0x1F8
};

void Class_000B1FA0::sub_000B1FA0(float a1)
{
    int t4;

    if (m_Field08) {
        if (m_Field1F8) goto L_47;
        if (DAT_00393980 > m_Field1B4) goto L_47;
        t4 = m_Field08->sub_000B4990();
        if (!t4) goto L_47;
        sub_000B0EE0(*(float*)(t4 + 8) * a1, t4);
    }
L_47:
    ;
}
