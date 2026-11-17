// bin: proto
// va: 0x001FEDD0
// tool: the portal's starter code (no AI)
// sub_001FEDD0 (0x001FEDD0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001FEDD0
{
public:
    void sub_001FEDD0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void Class_001FEDD0::sub_001FEDD0(int a1)
{
    int r_edx;

    *(int*)a1 = 0;
    r_edx = m_Field04;
    if (!r_edx) {
        m_Field00 = a1;
        m_Field04 = a1;
        m_Field08 += 1;
        return;
    }
    *(int*)r_edx = a1;
    m_Field04 = a1;
    m_Field08 += 1;
}
