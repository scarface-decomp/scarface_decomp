// bin: proto
// va: 0x00297E30
// tool: the portal's starter code (no AI)
// sub_00297E30 (0x00297E30, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field18
{
    int sub_00057190();
};

class Class_00297E30
{
public:
    void sub_00297E30();
    void sub_00297BD0();
    char m_pad00[0x18];
    Field18* m_Field18; // +0x18
    char m_pad1C[0xC];
    unsigned short m_Field28; // +0x28
    char m_pad2A[0x2];
    unsigned char m_Field2C; // +0x2C
};

void Class_00297E30::sub_00297E30()
{
    int t1;

    m_Field28 -= 1;
    if (!m_Field28) {
        if (m_Field2C & 15) goto L_2E;
        t1 = m_Field18->sub_00057190();
        if (((unsigned char)(((unsigned int)*(int*)(t1 + 120)) >> 11)) & 1) goto L_2E;
        sub_00297BD0();
        return;
    }
L_2E:
    ;
}
