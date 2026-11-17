// bin: xb
// va: 0x00058410
// tool: the portal's starter code (no AI)
// sub_00058410 (0x00058410, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00058410
{
public:
    void sub_00058410(float a1, float a2);
    char m_pad00[0x68];
    float m_Field68; // +0x68
    float m_Field6C; // +0x6C
    char m_pad70[0x4];
    float m_Field74; // +0x74
    char m_pad78[0x8];
    unsigned char m_Field80; // +0x80
};

void Class_00058410::sub_00058410(float a1, float a2)
{
    unsigned char t1;

    if (a2 > m_Field6C) {
        t1 = m_Field80;
        m_Field74 = a2;
        m_Field80 = (unsigned char)(t1 | 4);
        m_Field68 = (a2 - m_Field6C) * a1;
    }
}
