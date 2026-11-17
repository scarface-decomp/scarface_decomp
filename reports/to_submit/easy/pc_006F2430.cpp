// bin: pc
// va: 0x006F2430
// tool: the portal's starter code (no AI)
// sub_006F2430 (0x006F2430, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F2430
{
public:
    void* sub_006F2430();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void* Class_006F2430::sub_006F2430()
{
    m_Field04 = (int)(&m_Field04);
    m_Field08 = (int)(&m_Field04);
    m_Field0C = (int)(&m_Field04);
    m_Field10 = 0;
    m_Field00 = (int)(&m_Field04);
    return &m_Field04;
}
