// bin: proto
// va: 0x001DD400
// tool: the portal's starter code (no AI)
// sub_001DD400 (0x001DD400, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001DD400
{
public:
    void sub_001DD400(int a1);
    char m_pad00[0xC4];
    int m_FieldC4; // +0xC4
    int m_FieldC8; // +0xC8
};

void Class_001DD400::sub_001DD400(int a1)
{
    m_FieldC4 = a1;
    if (a1) {
        m_FieldC8 = *(int*)(a1 + 16);
        return;
    }
    m_FieldC8 = 0;
}
