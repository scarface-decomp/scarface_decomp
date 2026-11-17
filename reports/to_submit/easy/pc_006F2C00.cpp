// bin: pc
// va: 0x006F2C00
// tool: the portal's starter code (no AI)
// sub_006F2C00 (0x006F2C00, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F2C00
{
public:
    int sub_006F2C00(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_006F2C00::sub_006F2C00(int a1)
{
    if (!m_Field00) {
        m_Field00 = a1;
        *(int*)(a1 + 4) = 0;
        m_Field04 = a1;
        *(int*)a1 = 0;
        return a1;
    }
    *(int*)m_Field04 = a1;
    *(int*)(a1 + 4) = m_Field04;
    m_Field04 = a1;
    *(int*)a1 = 0;
    return a1;
}
